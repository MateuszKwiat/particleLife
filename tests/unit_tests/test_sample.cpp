#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

TEST(MathTest, Addition) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_NE(add(2, 2), 5);
}

TEST(MathTest, Subtraction) {
    EXPECT_EQ(sub(3, 2), 1);
    EXPECT_EQ(sub(2, 2), 0);
}