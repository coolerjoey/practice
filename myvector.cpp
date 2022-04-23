//
// Created by cooler on 20-9-3.
//
#include "myvector.h"

//判断A中是否含有B
bool find_B_in_A(vector<int> A,vector<int> B){
    for(int i=0;i<A.size();i++){
        if(B[0]==A[i]){
            int j=1;
            for(;j<B.size();j++){
                if((i+j)>A.size() || B[j]!=A[i+j]) break;
            }
            if(j==B.size()) return true;
        }
    }
    return false;
}

