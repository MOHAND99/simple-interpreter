cmake_minimum_required(VERSION 3.15)
project(simple_interpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(simple_interpreter main.cpp evaluate/Evaluate.cpp evaluate/Evaluate.h validation/Validate.cpp validation/Validate.h statement/SolvedStatement.cpp statement/SolvedStatement.h evaluate/EvaluateFunction.cpp evaluate/EvaluateFunction.h evaluate/EvaluateConditionStatement.cpp evaluate/EvaluateConditionStatement.h evaluate/EvaluateArithmeticStatment.cpp evaluate/EvaluateArithmeticStatment.h statement/Statement.cpp statement/Statement.h FileReader.cpp FileReader.h statement/FunctionStatement.cpp statement/FunctionStatement.h statement/ConditionStatmenet.cpp statement/ConditionStatmenet.h statement/Classify.cpp statement/Classify.h statement/ArithmeticStatement.cpp statement/ArithmeticStatement.h)