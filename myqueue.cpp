//
// Created by cooler on 20-7-12.
//
#include "myqueue.h"

myqueue::myqueue(){
    while (!stack_append.empty())
    {
        stack_append.pop();
    }
     while (!stack_dele.empty())
    {
        stack_dele.pop();
    }
}

void myqueue::appendTail(int val){
    stack_append.push(val);
    cout << "在队列尾插入 " << val << endl;
}

int myqueue::deleteHead(){
    if(stack_append.empty() && stack_dele.empty()){
        cout << "队列为空!" <<endl;
        return -1;
    }
    int res;
    if(!stack_dele.empty()){
        res = stack_dele.top();
        stack_dele.pop();
    }else{
        while(stack_append.size() != 1){
            stack_dele.push(stack_append.top());
            stack_append.pop();
        }
        res = stack_append.top();
        stack_append.pop();
    }
    cout << "删除队列首 " << res << endl;
    return res;
}









