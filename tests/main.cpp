#include "gtest/gtest.h"
#include "basic_check.cpp"
//#define RUN_NETWORK_TESTS
#ifdef RUN_NETWORK_TESTS
#include "network_tests.cpp"
#endif
namespace {
    TEST(main_check, test_eq) {
        ASSERT_EQ(0, 0);
    }
}
int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}