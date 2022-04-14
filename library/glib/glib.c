/*
 * helloglib.c
 * Using glib libraries to do a hello world
 * Compile with:
 * gcc helloglib.c `pkg-config --cflags --libs glib-2.0` -o helloglib
 */
#include <glib.h>

int main(void) {
    GString *my_string = g_string_new("This Hello world is %d chars long\n");
    g_print(my_string->str, my_string->len);
    g_string_free(my_string, TRUE);
    return 0;
}
