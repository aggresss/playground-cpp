int tcl_getaddrinfo(const char *node, unsigned port, const struct addrinfo *hints, struct addrinfo **res)

{
    tcl_thread_t pid;
    st_addrinfoparas paras;
    /* 把输入参数放入一个结构体传给子线程 */
    memset(&paras, 0, sizeof(st_addrinfoparas));
    paras.node = node;
    paras.servname = servname;
    paras.hints = hints;
    paras.res = res;
    paras.pid = pthread_self(); /*主线程自己的pid，传给子线程*/
    paras.endflag = END_FLAG;   /* END_FLAG = 12345，函数退出时置0，标志本函数退出*/
    /* 创建子线程，子线程入口函数为tcl_thread_getaddrinfo */
    int ret = tcl_clone(&pid, thread_getaddrinfo, (void *) &paras, TCL_THREAD_PRIORITY_INPUT);
    if (ret) {
        return -1;
    }
    /* 循环查看tcl_thread_getaddrinfo是否成功返回*/
    mtime_t start = mdate();
    int64_t nWaitSec = 5 * 1000 * 1000; //5s
    int btimeout = 1;
    while ((mdate() - start) < nWaitSec) {
        ret = pthread_kill(pid, 0);
        if (0 == ret) /*子线程仍然存在，说明getaddrinfo仍然在阻塞状态*/
        {
            usleep(50 * 1000); //sleep 50ms
        } else if (ESRCH == ret) /*子线程已经不存在，说明getaddrinfo成功返回了*/
        {
            btimeout = 0; // not timeout
            break;
        }
    };
    /* 根据超时标志和输出参数，判断子线程是否自行结束，是则返回成功，否则返回失败*/
    if ((0 == btimeout) && (NULL != *res)) {
        ret = 0;
    } else {
        ret = -1;
    }
    paras.endflag = 0;/*清零本函数标志*/
    return ret;
}

void* thread_getaddrinfo(void *obj)
{
    mtime_t start = mdate();
    /* 设置自己为可分离线程 */
    tcl_thread_t pid = pthread_self();
    pthread_detach(pid);
    /* 把输入参数都复制到本地, 以避免thread_getaddrinfo早于本线程退出，造成参数失效*/
    st_addrinfoparas* inputparas = (st_addrinfoparas*) obj;
    const char *node = strdup(inputparas->node);
    char *servname = strdup(inputparas->servname);
    struct addrinfo hints;
    hints.ai_socktype = inputparas->hints->ai_socktype;
    hints.ai_protocol = inputparas->hints->ai_protocol;
    hints.ai_flags = inputparas->hints->ai_flags;
    struct addrinfo* res = NULL;
    tcl_thread_t pid_master = inputparas->pid;

    /* getaddrinfo 也许会阻塞很长时间 */
    int ret = getaddrinfo(node, servname, &hints, &res);
    if (0 != ret) {
        goto exit;
    }
    /* getaddrinfo返回了，现在看看tcl_getaddrinfo线程是否还存在 */
    ret = pthread_kill(pid_master, 0);
    if (0 == ret && (mdate() - start) < 4500000)/*存在且getaddrinfo实际上的执行时间小于4.5s*/
    {
        if ((inputparas == NULL) || (inputparas->res == NULL)) {
            printf("thread_getaddrinfo pid:%u: inputparas == NULL\r\n", pid);
            freeaddrinfo(res);
            goto exit;
        }
        if (inputparas->endflag != END_FLAG) {
            printf("thread_getaddrinfo pid:%u: tcl_getaddrinfo %u has gone\r\n", pid, pid_master);
            freeaddrinfo(res);
            goto exit;
        }

        /*写输出参数*/
        *(inputparas->res) = res;
    } else /* cl_getaddrinfo线程不存在了 */
    {
        freeaddrinfo(res);
    }
    exit: free(node);
    free(servname);
    pthread_exit(NULL);
}

