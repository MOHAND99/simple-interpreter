cmake_minimum_required(VERSION 3.16)
project(simple_interpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(simple_interpreter main.cpp Sources/FileReader.cpp Headers/FileReader.h Sources/Evaluate.cpp Headers/Evaluate.h Sources/Validation.cpp Headers/Validation.h Sources/Statment.cpp Headers/Statment.h Sources/Interpretation.cpp Headers/Interpretation.h Sources/AssignmentStatment.cpp Headers/AssignmentStatment.h)