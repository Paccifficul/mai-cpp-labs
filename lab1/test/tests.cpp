#include "../include/task.h"
#include <gtest/gtest.h>

TEST(test1, BasicAssertion) {
    std::string s = "Hello World!";

    std::string res = removeVowels(s);

    EXPECT_EQ(res, "Hll Wrld!");
}

TEST(test2, BasicAssertion) {
    std::string s = "Hallo Welt!";

    std::string res = removeVowels(s);

    EXPECT_EQ(res, "Hll Wlt!");
}

TEST(test3, BasicAssertion) {
    std::string s = "Bruh hehe booy";

    std::string res = removeVowels(s);

    EXPECT_EQ(res, "Brh hh b");
}
