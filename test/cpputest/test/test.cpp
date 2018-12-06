/* file: test.c */

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

extern "C"
{
#include "sample.h"
}


/* define a TEST_GROUP named sample */
TEST_GROUP(sample)
{
    void setup()
    {
        printf ("test setup ......\n");
    }

    void teardown()
    {
        printf ("test teardown ......\n");
    }
};

/* define a TEST_GROUP TEST named ret_int_success */
TEST(sample, ret_int_success)
{
    int sum = ret_int(1, 2);
    CHECK_EQUAL(sum, 3);
}

/* define a TEST_GROUP TEST, named ret_int_failed */
TEST(sample, ret_int_failed)
{
    int sum = ret_int(1, 2);
    CHECK_EQUAL(sum, 4);
}

int main(int argc, char *argv[])
{
    CommandLineTestRunner::RunAllTests(argc, argv);
    return 0;
}

