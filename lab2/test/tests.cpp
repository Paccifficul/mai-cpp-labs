#include "../include/five.hpp"
#include <gtest/gtest.h>


/*TEST(test1, BasicAssertion) {
    Five f1 = Five("104");
    Five f2 = Five(2, '2');

    Five res = f1 + f2;

    Five currectRes = Five("131");

    EXPECT_EQ(res, currectRes);
}

TEST(test2, BasicAssertion) {
    Five f1 = Five("310");
    Five f2 = Five({'1', '4', '2'});

    Five res = f1 - f2;

    Five currectRes = Five("113");

    EXPECT_EQ(res, currectRes);
}

TEST(test3, BasicAssertion) {
    Five f1 = Five("43214");
    Five f2 = Five(5, '1');

    f1 += Five("4301");
    f1 -= f2;
    f2 += f1;

    f2 = f1 + f2; 

    Five res = f1 + f2;
    Five curreectRes = Five("144424");

    EXPECT_EQ(res, curreectRes);
}

TEST(test4, BasicAssertion) {
    Five f1 = Five({'0', '0', '2', '4', '3', '0'});
    Five f2 = Five(4, '1');
    
    f1 -= f2;

    bool res = (f1 > f2);

    EXPECT_TRUE(res);
}

TEST(test5, BasicAssertion) {
    Five f1 = Five({'0', '0', '0', '0', '1', '4', '3'});
    Five f2 = Five("00000000143");

    bool res1 = (f1 >= f2);
    bool res2 = (f1 == f2);

    bool res = res1 && res2;

    EXPECT_TRUE(res);
}

TEST(test6, BasicAssertion) {
    Five f1 = Five("1423");
    Five f2 = Five("43123");
    Five f3 = Five("1112");

    bool res1 = (f1 >= f2);
    bool res2 = (f3 > f1);
    bool res3 = (f2 == f3);

    EXPECT_FALSE(res1 || res2 || res3);
}

TEST(test7, BasicAssertion) {
    Five f1 = Five("1234");
    Five f2 = Five({'4', '2', '1'});

    Five res = f1 + f2 - Five("22");
    Five currectRes = Five("2133");

    EXPECT_EQ(res, currectRes);
}*/