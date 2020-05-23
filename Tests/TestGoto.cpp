//
// Created by Zayton on 5/23/2020.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Statements/GotoStatement.h"
TEST(TestGoto,TestGoto){
    ASSERT_EQ(GotStatement::isValid("label x : y = 10 +5"),1);
    ASSERT_EQ(GotStatement::isValid("label xyyy y :  = 10 +5"),0);
    ASSERT_EQ(GotStatement::isValid("label x-g hh : y = 10 +5"),0);
    ASSERT_EQ(GotStatement::isValid("label 1dd : y = 10 +5"),0);
    ASSERT_EQ(GotStatement::isValid("labelx : y = 10 +5"),0);
    ASSERT_EQ(GotStatement::isValid("if x<y ? x=10 :y=5 goto ggg"),1);
    ASSERT_EQ(GotStatement::isValid("if x<y ? x=10 :y=5 gotoggg"),0);
    ASSERT_EQ(GotStatement::isValid("if x<y ? x=10 :y=5 goto gg g"),0);
    ASSERT_EQ(GotStatement::isValid("if x<y ? x=10 :y=5 goto 1gg"),0);
    ASSERT_EQ(GotStatement::isValid("if x<y ? x=10 :y=5 goto g1 g g "),0);

}

