//
// Created by cooler on 20-7-12.
//
#include "mystack.h"

MYStack::MYStack() {
}

int MYStack::top(){
    return stack.back();
}
int MYStack::pop() {
    int res = stack.back();
    for(int i=0;i<stack.size()-1;i++){
        int temp = stack.front();
        stack.push(temp);
    }
    stack.pop();
    return  res;
}
void MYStack::push(int x) {
    stack.push(x);
}
bool MYStack::empty() {
    return stack.empty();
}

MinStack::MinStack(void){
    while(!stackMin.empty()) stackMin.pop();
    while(!stackVal.empty()) stackVal.pop();
}
void MinStack::push(int x){
    stackVal.push(x);
    if(stackMin.empty() || x<stackMin.top()) stackMin.push(x);
    else stackMin.push(stackMin.top());
    cout<<"压入"<<x<<endl;
}
void MinStack::pop(void){
    if(stackVal.empty()) {
        cout<<"空栈！"<<endl;
    }
    else{
        cout<<"弹出栈顶元素:"<<stackVal.top()<<endl;
        stackVal.pop();
        stackMin.pop();
    }
}
int MinStack::top(void){
    if(stackVal.empty()) {
        cout<<"空栈！"<<endl;
        return 0;
    }
    else{
        cout<<"栈顶元素："<<stackVal.top()<<endl;
        return stackVal.top();
    }

}
int MinStack::min(void){
    if(stackVal.empty()) {
        cout<<"空栈！"<<endl;
        return 0;
    }
    cout<<"栈中最小值："<<stackMin.top()<<endl;
    return stackMin.top();
}









