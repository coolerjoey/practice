//
// Created by cooler on 20-8-17.
//

#pragma once

#include <iostream>
#include <stack>
using namespace std;

//ʹ������ջʵ�ֶ���
class myqueue {
public:
    myqueue(void);
    ~myqueue(void){};
    void appendTail(int value) ;
    int deleteHead(void);

private:
    stack<int> stack_append,stack_dele;
};
