#include <gtest/gtest.h>
#include <particleLife/core/temp.h>
#include <particleLife/render/temp1.h>
#include <particleLife/ui/temp2.h>

TEST(TempTest, Addition) { EXPECT_EQ(addition(3, 2), 5); }

TEST(TempTest, Sub) { EXPECT_EQ(sub(3, 2), 1); }

TEST(TempTest, Prod) { EXPECT_EQ(prod(3, 2), 6); }
