int post_test() {
    char szXML[2048];
    char szVal[256];

    ghttp_request *request = NULL;
    ghttp_status status;
    char *buf;
    char retbuf[128];
    int len;

    strcpy(szXML, "POSTDATA=");
    sprintf(szVal, "%d", 15);
    strcat(szXML, szVal);

    printf("%s\n", szXML);      //test

    request = ghttp_request_new();
    if (ghttp_set_uri(request, uri) == -1)
        return -1;
    if (ghttp_set_type(request, ghttp_type_post) == -1)     //post
        return -1;

    ghttp_set_header(request, http_hdr_Content_Type,
            "application/x-www-form-urlencoded");
    //ghttp_set_sync(request, ghttp_sync); //set sync
    len = strlen(szXML);
    ghttp_set_body(request, szXML, len);    //
    ghttp_prepare(request);
    status = ghttp_process(request);
    if (status == ghttp_error)
        return -1;
    buf = ghttp_get_body(request);  //test
    sprintf(retbuf, "%s", buf);
    ghttp_clean(request);
    return 0;
}

