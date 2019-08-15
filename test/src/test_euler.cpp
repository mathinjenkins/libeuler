#include <gtest/gtest.h>
#include <euler/euler.h>

TEST(EulerTest1, getE)
{
    auto result = GetE(1);
    ASSERT_TRUE(result == 2);
}

TEST(EulerTest2, getE)
{
    auto result = GetE(2);
    ASSERT_TRUE(result == 2.25);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}