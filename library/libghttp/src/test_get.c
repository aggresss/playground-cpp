*
 * libghttp_get.c
 *  http get test
 *  Created on: 2013年10月25日
 *      Author: elesos.com
 */
 
#include <stdio.h>
#include <string.h>
#include <ghttp.h>
int main(int argc, char **argv)
{
    char *uri = "http://www.elesos.com/%E9%A6%96%E9%A1%B5";
    ghttp_request *request = NULL;
    ghttp_status status;
    FILE * pFile;
    char *buf;
    int bytes_read;
    int size;
 
    pFile = fopen ( "elesos.html" , "wb" );
 
    request = ghttp_request_new();
    if(ghttp_set_uri(request, uri) == -1)
       return -1;
    if(ghttp_set_type(request, ghttp_type_get) == -1)//get
    	 return -1;
    ghttp_prepare(request);
    status = ghttp_process(request);
    if(status == ghttp_error)
    	 return -1;
    printf("Status code -> %d\n", ghttp_status_code(request));
    buf = ghttp_get_body(request);
 
    bytes_read = ghttp_get_body_len(request);
    size = strlen(buf);//size == bytes_read
    fwrite (buf , 1 ,size , pFile );
    fclose(pFile);
    return 0;
}

