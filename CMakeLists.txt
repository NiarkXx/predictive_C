cmake_minimum_required(VERSION 3.9)
project(predictive_C)

set(CMAKE_CXX_STANDARD 11)

add_executable(predictive_C
        bibli_doc.c
        bibli_doc.h
        bibli_pred.c
        bibli_pred.h
       # main.c
        testFunction.c)

#[[add_executable(predictive_C
        testFunction.c
)]]
