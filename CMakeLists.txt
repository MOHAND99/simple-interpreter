cmake_minimum_required(VERSION 3.16)
project(simple_interpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(simple_interpreter main.cpp Evaluate.cpp Evaluate.h Validate.cpp Validate.h SolvedStatement.cpp SolvedStatement.h EvaluateFunction.cpp EvaluateFunction.h EvaluateConditionStatement.cpp EvaluateConditionStatement.h EvaluateArithmeticStatment.cpp EvaluateArithmeticStatment.h Statement.cpp Statement.h FileReader.cpp FileReader.h)