
## Reference

- [https://www.gnu.org/software/pth/related.html](https://www.gnu.org/software/pth/related.html)
- [http://state-threads.sourceforge.net/](http://state-threads.sourceforge.net/)
- [https://sourceforge.net/projects/state-threads/](https://sourceforge.net/projects/state-threads/)
- [https://en.wikipedia.org/wiki/State_Threads](https://en.wikipedia.org/wiki/State_Threads)
- [https://en.wikipedia.org/wiki/Netscape_Portable_Runtime](https://en.wikipedia.org/wiki/Netscape_Portable_Runtime)
- [https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSPR](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSPR)x`

- [https://zhuanlan.zhihu.com/p/48219407](https://zhuanlan.zhihu.com/p/48219407)
- [https://www.cnblogs.com/NerdWill/p/6166220.html](https://www.cnblogs.com/NerdWill/p/6166220.html)

- [https://winlin.blog.csdn.net/article/details/40948277](https://winlin.blog.csdn.net/article/details/40948277)
- [https://blog.csdn.net/win_lin/article/details/41009137](https://blog.csdn.net/win_lin/article/details/41009137)
- [https://blog.csdn.net/win_lin/article/details/40978665](https://blog.csdn.net/win_lin/article/details/40978665)

- [https://blog.csdn.net/tao_627/article/details/45788013](https://blog.csdn.net/tao_627/article/details/45788013)
- [https://coolshell.cn/articles/12012.html](https://coolshell.cn/articles/12012.html)

## Note

st_init() 创建一个 idle_thread, 初始化 _ST_RUNQ / _ST_IOQ / _ST_ZOMBIEQ 三个队列，把当前调用者初始化成原始函数（通常 st_init 会在 main() 里面调用,所以这个原始的 thread 相当于是主线程）。

线程调度的核心，根据 io 或者 timeout 调度，调度其实就是 idle 线程做的，idle_thread 函数，其实就是整个IO和定时器相关的本体函数了。st 会在每一次 _ST_RUNQ 运行完成后，调用 idle_thread 来获取可读写的io和定时器。这个我们后续再说。

st_poll 本质上会调用并且切换上下文。

基于 Mult-Threading 范式, 内部使用 EDSM 机制
