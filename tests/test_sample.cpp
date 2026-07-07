#include <gtest/gtest.h>
#include <particleLife/core/temp.hpp>
#include <particleLife/render/temp1.hpp>
#include <particleLife/ui/temp2.hpp>

TEST(TempTest, Addition) { EXPECT_EQ(addition(3, 2), 5); }

TEST(TempTest, Sub) { EXPECT_EQ(sub(3, 2), 1); }

TEST(TempTest, Prod) { EXPECT_EQ(prod(3, 2), 6); }

TEST(TempTest, BranchedFunction) { EXPECT_EQ(branchedFunction(1), 1); }
