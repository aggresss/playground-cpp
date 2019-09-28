#include <stdio.h>
#include <stdlib.h>

static int put_buf_to_file(const char *pFilename, unsigned char *pbuf, size_t pLen)
{
    FILE *fp = NULL;

    fp = fopen(pFilename, "wb");
    if (!fp) {
        return -1;
    }
    fwrite(pbuf, 1, pLen, fp);
    fclose(fp);
    return 0;
}


static int read_file_to_buf(const char *pFilename, unsigned char **pBuf, size_t *pLen)
{
    int ret = 0;
    FILE *pFile = NULL;
    size_t nLen = 0;
    unsigned char *pData = NULL;

    pFile = fopen(pFilename, "rb");
    if (pFile == NULL) {
        return -1;
    }

    fseek(pFile, 0, SEEK_END);
    nLen = ftell(pFile);
    fseek(pFile, 0, SEEK_SET);

    pData = malloc(nLen);
    if(!pData) {
        ret = -1;
        goto exit;
    }
    ret = fread(pData, 1, nLen, pFile);
    if (ret <= 0) {
        ret = -1;
        goto exit;
    }

    *pBuf = pData;
    *pLen = nLen;
    pData = NULL;
    ret = 0;

exit:
    if (pData) {
        free(pData);
    }
    if (pFile) {
        fclose(pFile);
    }
    return ret;
}

