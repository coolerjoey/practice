//
// Created by cooler on 20-8-14.
//

#pragma once

#include <iostream>
#include <algorithm>
#include "io_put.h"
#include "mytree.h"
#include <map>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};
struct DualListNode{
    int val;
    DualListNode *next;
    DualListNode *previous;
    DualListNode(int x):val(x),next(nullptr),previous(nullptr){}
    DualListNode(int x,DualListNode *_next,DualListNode *_previous):val(x),next(_next),previous(_previous){}
};

enum ListType_t{
    ListTypeCommon,
    ListTypeLoop
};

class MyList {
public:
    static vector<int> reversePrint1(ListNode* head);
    static vector<int> reversePrint2(ListNode* head);
    static ListNode* reverseList(ListNode* head) ;
    static ListNode* removeNthFromEnd(ListNode *head,int n);
    static ListNode* ListNodeInit(ListType_t type);
    static ListNode* DeleteDuplication_1(ListNode *head);
    static ListNode* DeleteDuplication_2(ListNode *head);
    static void printListNode(ListNode *head);
    static ListNode* EntryNodeOfLoop(ListNode *head);
    static  void divide_to_two_list(ListNode *head,ListNode *list1,ListNode *list2);
    static  DualListNode* treeToDoublyList(mytree* root);
    static ListNode* deleteNode(ListNode* head, int val);
};

