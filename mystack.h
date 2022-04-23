//
// Created by cooler on 20-7-12.
//

#ifndef LEETCODE_19_MYSTACK_H
#define LEETCODE_19_MYSTACK_H

#include <queue>
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack(void);
    void push(int x);
    void pop(void);
    int top(void);
    int min(void);

private:
    stack<int> stackVal;
    stack<int> stackMin;
};

class MYStack{
public:
    MYStack(void);
    void push(int x);
    int pop(void);
    int top(void);
    bool empty(void);

private:
    queue<int> stack;
};


#endif //LEETCODE_19_MYSTACK_H
