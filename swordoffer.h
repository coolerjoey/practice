//
// Created by cooler on 20-8-10.
//

#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include "MyList.h"
#include "mytree.h"
#include "myqueue.h"
#include "mystack.h"
using namespace std;


class swordoffer {
public:
    static void test_03(void);
    static void test_04(void);
    static void test_05(void);
    static void test_06(void);
    static void test_07(void);
    static void test_09(void);
    static void test_10_1(void);
    static void test_10_2(void);
    static void test_11(void);
    static void test_12(void);
    static void test_13(void);
    static void test_14_1(void);
    static void test_15(void);
    static void test_16(void);
    static void test_17(void);
    static void test_18_1(void);
    static void test_18_2(void);
    static void test_19(void);

    void offer_04_test(void);
    void offer_05_test(void);
    void offer_07_test(void);
    void offer_09_test(void);
    void offer_10_test(int n);
    void offer_11_test(void);
    void offer_12_test(void);
    void offer_13_test(void);
    void offer_14_test(void);
    void offer_15_test(void);
    void offer_16_test(void);
    void offer_17_test(void);
    void offer_19_test(void);
    void offer_20_test(void);
    void offer_21_test(void);
    void offer_22_test(void);
    void offer_23_test(void);
    void offer_25_test(void);
    void offer_26_test(void);
    void offer_27_test(void);
    void offer_28_test(void);
    void offer_29_test(void);
    void offer_30_test(void);
    void offer_31_test(void);
    void offer_32_1_test(void);
    void offer_32_2_test(void);
    void offer_32_3_test(void);
    void offer_33_test(void);
    void offer_34_test(void);
    void offer_37_test(void);
public:
    int findRepeatNumber(vector<int>&) ;
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);
    string replaceSpace(string s) ;
    vector<int> reversePrint(ListNode* head) ;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
    int fib(int n);
    int minArray(vector<int>& numbers);
    int movingCount(int m, int n, int k);
    void printNumbers(int n) ;

};


