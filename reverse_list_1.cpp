/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *n=NULL) :val{x}, next{n} {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode x(0), *newHead = &x;
        newHead->next = head;
        if (!head)
            return head;
        while(head->next) {
            ListNode *temp = head->next;
            head->next = temp->next;
            temp->next = newHead->next;
            newHead->next = temp;
        }
        return newHead->next;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *old = NULL, *cur = head;
        while(cur) {
            ListNode *temp = cur->next;
            cur->next = old;
            old = cur;
            cur = temp;
        }
        return old;
    }
};
void print_list(ListNode *head)
{
    for(;head; head = head->next) {
        cout<<head->val<<",";
    }
    cout<<endl;
}

int main()
{
    ListNode x1{1,NULL};
    ListNode x2{2,&x1};
    ListNode x3{3,&x2};
    ListNode x4{4,&x3};
    ListNode x5{5,&x4};
    Solution s;
    print_list(s.reverseList(&x5));
}
