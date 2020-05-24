//
// Created by Zayton on 5/23/2020.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Statements/GotoStatement.h"
TEST(TestGoto,TestGoto){
    ASSERT_EQ(GotoStatement::isValid("if x<y ? x=10 :y=5 goto ggg"),0);
    ASSERT_EQ(GotoStatement::isValid("x = 5+10 goto ggg"),0);
    ASSERT_EQ(GotoStatement::isValid("goto gg g"),0);
    ASSERT_EQ(GotoStatement::isValid(" : goto 1gg"),0);
    ASSERT_EQ(GotoStatement::isValid("goto g1 g g "),0);
    ASSERT_EQ(GotoStatement::isValid("goto g1 "),1);


}

