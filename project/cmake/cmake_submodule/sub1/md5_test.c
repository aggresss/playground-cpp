#include <stdio.h>
#include <string.h>
#include "md5.h"

/*
 * Verification result generate from
 * http://tool.oschina.net/encrypt?type=2
 *
 * */

#define ASSERT_SUCCESS (0)
#define ASSERT_FAIL    (1)

#define MD5_DIGEST_SIZE 16

int main(int argc, const char * argv[]) {
    int i;
    char data[] = "aggresss";
    char out[MD5_DIGEST_SIZE] = {0};
    char out_hexstr[MD5_DIGEST_SIZE * 2 + 1] = {0};
    char expect_md5_result[] = "b665a16ea74e08a4003f0257f215c754";

    /* md5 workflow */
    md5_state_t md5_state;
    md5_init(&md5_state);
    md5_append(&md5_state, (unsigned char *)data, (int)strlen(data));
    md5_finish(&md5_state, (unsigned char *)out);

    for(i = 0; i< MD5_DIGEST_SIZE; i++) {
        sprintf((char *)(out_hexstr + i * 2), "%02x", *(unsigned char *)(out + i));
    }
    printf("data: %s\nMD5: %s\n", data, out_hexstr);

    return strncmp(expect_md5_result, out_hexstr, MD5_DIGEST_SIZE * 2);
}

