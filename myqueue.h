//
// Created by cooler on 20-8-17.
//

#pragma once

#include <iostream>
#include <stack>
using namespace std;

//使用两个栈实现队列
class myqueue {
public:
    myqueue(void);
    ~myqueue(void){};
    void appendTail(int value) ;
    int deleteHead(void);

private:
    stack<int> stack_append,stack_dele;
};
