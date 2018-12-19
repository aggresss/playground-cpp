#include <gmock/gmock.h>
#include <iostream>

using namespace testing;

class PTest: public Test
{
    public:
};

TEST_F(PTest, DummyTest)
{
    std::cout << "Dummy Test should always pass." << std::endl;
    ASSERT_THAT(1, Eq(1));
}

TEST_F(PTest, DummyFailingTest)
{
    std::cout << "Dummy Test should always fail." << std::endl;
    ASSERT_THAT(2, Eq(2));
}

int main(int argc, char** argv)
{
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
