// #include "leetcode_offer.h"

#include "swordoffer.h"

//#include <bits/stdc++.h>  //包含所有头文件

void test(){
    static int i = 1;
    if(i++ == 10) return;
    test();
}


ListNode *detectCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            ListNode *tmp = head;
            while(true){
                fast = fast->next;
                tmp = tmp->next;
                if(fast == tmp) break;
            }
            return fast;
        }
    }
    return nullptr;
}

int main() {
    ListNode* head = MyList::ListNodeInit(ListTypeCommon);
    ListNode* res = detectCycle(head);
    cout << "结果是：" << endl;
    MyList::printListNode(res);
    return 0;
}




