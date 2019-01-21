/*
 * Fork from wolfmqtt example file
 * https://github.com/wolfSSL/wolfMQTT/blob/master/examples/mqttexample.c
 * */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* argument parsing */
int myoptind = 0;
const char* myoptarg = NULL;


int mygetopt(int argc, const char** argv, const char* optstring)
{
    static const char* next = NULL;

    char  c;
    char* cp;

    if (myoptind == 0)
        next = NULL;   /* we're starting new/over */

    if (next == NULL || *next == '\0') {
        if (myoptind == 0)
            myoptind++;

        /* argument check */
        if (myoptind >= argc || argv[myoptind][0] != '-' ||
                                argv[myoptind][1] == '\0') {
            myoptarg = NULL;
            if (myoptind < argc)
                myoptarg = argv[myoptind];

            return -1;
        }

        /* No support long option */
        if (strncmp(argv[myoptind], "--", 2) == 0) {
            myoptind++;
            myoptarg = NULL;

            if (myoptind < argc)
                myoptarg = argv[myoptind];

            return -1;
        }

        /* argv[] start from 1 */
        next = argv[myoptind];
        next++;                  /* skip - */
        myoptind++;
    }

    /* c= *next; next++; */
    c = *next++;
    /* The C++ strchr can return a different value */
    cp = (char*)strchr(optstring, c);

    if (cp == NULL || c == ':')
        return '?';

    /* check option with argument */
    cp++;
    if (*cp == ':') {
        /* continuous argument */
        if (*next != '\0') {
            myoptarg = next;
            next     = NULL;
        }
        /* detached argument */
        else if (myoptind < argc) {
            myoptarg = argv[myoptind];
            myoptind++;
        }
        else
            return '?';
    }

    return c;
}
