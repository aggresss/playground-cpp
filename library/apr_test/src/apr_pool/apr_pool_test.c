#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <apr_general.h>
#include <apr_pools.h>

#define MEM_ALLOC_SIZE 1024

/**
 * memory pool sample code
 * @remark Error checks omitted
 */
int main(int argc, const char *argv[])
{
    apr_status_t rv;
    apr_pool_t *mp;
    char *buf1;
    char *buf2;

    /* per-process initialization */
    rv = apr_initialize();
    if (rv != APR_SUCCESS) {
        assert(0);
        return -1;
    }

    /* create a memory pool. */
    apr_pool_create(&mp, NULL);

    /* allocate memory chunks from the memory pool */
    buf1 = apr_palloc(mp, MEM_ALLOC_SIZE);
    buf2 = apr_palloc(mp, MEM_ALLOC_SIZE);

    /* destroy the memory pool. These chunks above are freed by this */
    apr_pool_destroy(mp);

    apr_terminate();
    return 0;
}

