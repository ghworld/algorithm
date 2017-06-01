cmake_minimum_required(VERSION 3.6)
project(algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp test.cpp findFirstCommonNode.cpp Box.cpp Box.h quickSort.cpp climbStairs.cpp trailingZeroes.cpp yinYong_dizhi.cpp LCS.cpp LIS.cpp Utils.h getKSamllNumberss.cpp mergeTwoLists.cpp extractSummary.cpp maximumSubarray.cpp heapSort.cpp)
add_executable(firstDemo ${SOURCE_FILES})