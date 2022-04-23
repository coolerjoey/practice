cmake_minimum_required(VERSION 3.6)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp mystack.cpp mystack.h offer.cpp offer.h MyList.cpp MyList.h mytree.cpp mytree.h myqueue.cpp myqueue.h io_put.cpp io_put.h exam.cpp .idea/myvector.cpp .idea/myvector.h myvector.cpp myvector.h PositionUtil.cpp PositionUtil.h position_vector.cpp position_vector.h mymath.cpp mymath.h PID.c PID.h)
add_executable(leetcode ${SOURCE_FILES})