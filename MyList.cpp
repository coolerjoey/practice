//
// Created by cooler on 20-8-14.
//

#include "MyList.h"

/* 逆序打印链表,栈方 */
vector<int> MyList::reversePrint1(ListNode* head){
    vector<int> res;
    stack<int> val_stack;
    while(head != nullptr){
        val_stack.push(head->val);
        head = head->next;
    }
    while (!val_stack.empty())
    {
        res.push_back(val_stack.top());
        val_stack.pop();
    }
    
    return res;
}

vector<int> res;
/* 逆序打印链表,递归方式 */
vector<int> MyList::reversePrint2(ListNode* head){
    if (head !=  nullptr)
    {
        reversePrint2(head->next);
        res.push_back(head->val);
    }
    return res;
}

//输出链表
void MyList::printListNode(ListNode *head){
    ListNode *temp = head;
//    cout<<"处理后的链表";
    while(temp){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

//反转节点
ListNode* MyList::reverseList(ListNode* head) {
    ListNode *prev=nullptr,*next=nullptr;
    while(head){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
//从尾部删除第ｎ个节点
ListNode* MyList::removeNthFromEnd(ListNode *head,int n){
    if(n==0) return head;   //一个都不删
    int i=0;
    ListNode *temp = head;
    while(temp){
        temp=temp->next;
        i++;
    }
    int size = i;
    i=0;
    temp = head;
    n = size-n+1;
    if(n==1){       //S删第一个节
        return head->next;
    }
    while(i++<n-2) temp = temp->next;
    ListNode* ListNodefree = temp->next;
    temp->next = temp->next->next;
//    free(ListNodefree);
    delete ListNodefree;
    return head;
}

//保留排序链表中的重复节点中的一个
ListNode* MyList::DeleteDuplication_1(ListNode *head){
    if(!head) return head;
    ListNode *p1=head;
    ListNode *p2=head->next;
    while(p2){
        if(p2->val == p1->val){
            p2 = p2->next;
            p1->next = p2;
        }
        else {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return head;
}
//删除递增排序链表中的重复节点
ListNode* MyList::DeleteDuplication_2(ListNode *head){
    if(!head || !head->next) return head;
    if(head->val == head->next->val) {
        head = DeleteDuplication_2(head->next->next);
    }
    else{
        head->next = DeleteDuplication_2(head->next);
    }
//    cout << "head地址: " << &(*head) << endl;
    return head;
}

//链表初始
ListNode* MyList::ListNodeInit(ListType_t type){
    cout<<"请输入链表序列：";
    vector<int>  v = io_put::input_numbers();
    if(v.size()==0) return nullptr;
    ListNode *head = new ListNode(v[0]);
    ListNode *p = head;
    bool loop_list=false;
    for(int i=1;i<v.size();i++){
        if(type == ListTypeLoop && find(v.begin(),v.end(),v[i]) != v.begin()+i){ /* 找成环链表 */
            ListNode* _temp = head;
            while(_temp->val!=v[i]) _temp = _temp->next;
            loop_list = true;
            p->next = _temp;
            break;
        }
        else {
            p->next = new ListNode(v[i]);
            p = p->next;
        }
    }
    ListNode *temp = head;
    if(!loop_list){
        p->next = nullptr;
        cout<<"输入的普通链表是";
        while(temp){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
    else{
        cout<<"输入的有环链表是";
        while(temp!=p){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<p->val<<"->"<<p->next->val<<endl;
    }
    return head;
}


//链表中环的入口节
ListNode* MyList::EntryNodeOfLoop(ListNode *head){
    if(!head) return head;
    ListNode *p = head;
    bool loop_find = false;
    map<int,bool> m;
    while(p){
        if(m[p->val]) {
            loop_find = true;
            break;
        }
        m[p->val] = true;
        p=p->next;
//        m.insert(map<int,bool>::value_type(p->val,true));
    }
    if(loop_find) return p;
    return nullptr;
}

//交替连接链表的结
//1->2->3->4->5->6生成两个链表->1->3->52->4->6
void MyList::divide_to_two_list(ListNode *head,ListNode *list1,ListNode *list2){
    ListNode *List_Odd = nullptr;
    ListNode *List_Even = nullptr;
    list1 = list2 = nullptr;
    ListNode *List_OddClone = List_Odd;
    ListNode *List_EvenClone = List_Even;
    if(!head) return;
    List_OddClone = List_Odd = head;
    List_EvenClone = List_Even = head->next;
    while(List_Odd){
        if(List_Even) {
            List_Odd->next = List_Even->next;
            List_Odd = List_Odd->next;
        }
        if(List_Odd) {
            List_Even->next = List_Odd->next;
            List_Even = List_Even->next;
        }
    }
    list1 = List_OddClone;
    list2 = List_EvenClone;
}

/* 删除链表中值为val的节点，要求输入的链表中没有重复的值*/
ListNode* MyList::deleteNode(ListNode* head, int val) {
    ListNode* p = head;
    if(p->val == val){ /* 删除头节点 */
        return head->next;
    }
    while(p->next){
        if(p->next->val == val){
            p->next = p->next->next;
            return head;
        }
        p = p->next;
    }
    if(p->val == val){
        p=nullptr;
    }
    return head;
}