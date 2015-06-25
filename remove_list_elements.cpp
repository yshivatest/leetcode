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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode x(0), *temp = &x;
        temp->next = head;
        while(temp->next) {
            if (temp->next->val == val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return x.next;
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
    ListNode x1{3,NULL};
    ListNode x2{2,&x1};
    ListNode x3{3,&x2};
    ListNode x4{4,&x3};
    ListNode x5{5,&x4};
    Solution s;
    print_list(s.removeElements(&x5, 3));
}
