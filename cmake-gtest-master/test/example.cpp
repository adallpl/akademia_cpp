#include "gtest/gtest.h"
#include "example.hpp"
#include <cmath>
#include <cassert>
/*TEST(ExampleTest, StringComparisonWorks) {
  EXPECT_STREQ("Ala", "Ala");
  EXPECT_STRNE("Ala", "kot");
}

TEST(ExampleTest, BrokenTest) {
    const char* text = "Ala";
    char buf[sizeof(text)];
    strcpy(buf, text);
    EXPECT_EQ(text, buf);
}

TEST(ExampleTest, FiveReturnsFive) {
    EXPECT_EQ(five(), 5);
}

TEST(ExampleTest, ListContains)
{
    List L1;
    L1.insert(1);
    L1.insert(3);
    L1.insert(4);
    L1.insert(5);
    L1.insert(7);
    L1.insert(9);
    EXPECT_EQ(L1.contains(1), 1); // drugi argument to wartosc oczekiwana
}

TEST(ExampleTest, List_el_Counts)
{
    List L1;
    L1.insert(1);
    L1.insert(3);
    L1.insert(4);
    L1.insert(5);
    EXPECT_EQ(L1.elemCount(), 4); // drugi argument to wartosc oczekiwana
}*/

TEST(RootsTest, PositiveDelta)
{
     //asercja


    Solution s = roots(1, -3, 2);
  //  ASSERT_EQ(s.count, 2); // rownosc

    double x1 = std::min(s.x1, s.x2);
    double x2 = std::max(s.x1, s.x2);

    const double eps = 1e-5;
//    EXPECT_TRUE(std::abs(s.x1 - 1.0) < eps
 //               || std::abs(s.x1 - 2.0));

  //  EXPECT_TRUE(std::abs(s.x2 - 1.0) < eps
  //              || std::abs(s.x2 - 2.0)); // mniej niezawdone niz tetoewanie z dopiudszceniem bledu

    EXPECT_NEAR(x1, 1.0, eps); // czy roznica mieszy wartosciami jest mnijsza od epsilona
    EXPECT_NEAR(x2, 2.0, eps);
    // to samo : std::abs(x1, -1.0) < eps;
    EXPECT_DOUBLE_EQ(x1, 1.0);
    EXPECT_DOUBLE_EQ(x2, 2.0);
    EXPECT_NE(s.x1, s.x2);

    EXPECT_FALSE(s.identity);
}

TEST(RootsTest, ZeroDelta)
{
    Solution s = roots(1, -2, 1); // delta = 0
    double x1 = std::min(s.x1, s.x2);
    double x2 = std::max(s.x1, s.x2);
    EXPECT_EQ(s.count, 1);
    EXPECT_DOUBLE_EQ(x1, 1.0);
    EXPECT_EQ(s.identity, 1);
}

