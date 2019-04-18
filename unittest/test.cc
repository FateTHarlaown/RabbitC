//
// Created by NorSnow_ZJ on 2019/4/18.
//
#include <gtest/gtest.h>

GTEST_API_ int main(int argc, char **argv) {
    testing::GTEST_FLAG(color) = "yes";
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}