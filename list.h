#ifndef _LIST_NODE_
#define _LIST_NODE_
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *n=NULL) :val{x}, next{n} {}
};

void print_list(ListNode *head)
{
    for(;head; head = head->next) {
        cout<<head->val<<",";
    }
    cout<<endl;
}
#endif
