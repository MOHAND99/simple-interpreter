//
// Created by Zayton on 5/23/2020.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Statements/GotoStatement.h"
TEST(TestGoto,TestGoto){
    // if CONDITION: STATEMENT_TO_EXECUTE_ON_TRUE
    // if x < y: goto ggg

    // Start with _ or a-Z
    // rest of the name is digit or _ or a-Z
    ASSERT_EQ(GotoStatement::isValid("if x<y ? x=10 :y=5 goto ggg"),0);
    ASSERT_EQ(GotoStatement::isValid("x = 5+10 goto ggg"),0);
    /*
     * isValid (assignment) -> true
     * AssignmentStatement { variableName = "x", expression = "5+10 goto ggg" }
     * execute -> ExpressionEvaluator( will evaluate "5+10 goto ggg )
     */
    ASSERT_EQ(GotoStatement::isValid("goto gg g"),0);
    ASSERT_EQ(GotoStatement::isValid(" : goto 1gg"),0);
    ASSERT_EQ(GotoStatement::isValid("goto g1 g g "),0);
    ASSERT_EQ(GotoStatement::isValid("goto g1 "),1);


}

