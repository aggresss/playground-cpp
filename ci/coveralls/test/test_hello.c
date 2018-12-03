#include <stdio.h>
#include "CuTest.h"
#include "cjson.h"
#include "../src/algorithm.h"

void test_hello_setup(CuTest *tc)
{
    printf("test_hello_setup.\n");
}

void test_hello_cleanup(CuTest *tc)
{
    printf("test_hello_cleanup.\n");
}

void test_hello_abs(CuTest *tc)
{
    CuAssertIntEquals(tc, 3, _abs(-3));
    CuAssertIntEquals(tc, 3, _abs(3));
}

void test_hello_max(CuTest *tc)
{
    CuAssertIntEquals(tc, 3, _max(2, 3));
    CuAssertIntEquals(tc, 3, _max(3, 2));
}

void test_hello_sort(CuTest *tc)
{
    int theList[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int i;
    _sort(theList, 10);
    for (i = 0; i < 10; i++) {
        CuAssertIntEquals(tc, i, theList[i]);
    }
}

CuSuite *test_hello_suite()
{
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, test_hello_setup);
    SUITE_ADD_TEST(suite, test_hello_abs);
    SUITE_ADD_TEST(suite, test_hello_max);
    SUITE_ADD_TEST(suite, test_hello_sort);
    SUITE_ADD_TEST(suite, test_hello_cleanup);

    return suite;
}

