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
    ListNode(int x, ListNode *n=NULL) : val{x}, next{n} {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
         n = n -m;
        m--;
        ListNode x(0), *newHead = &x;
        newHead->next = head;
        ListNode *temp1 = newHead, *temp2, *temp3, *temp4;
        while(m) {
            temp1 = temp1->next;
            m--;
        }
        temp2 = temp1->next;
        temp3 = temp2;
        //reverse from temp2
        while(n) {
            temp4 = temp3->next;
            temp3->next = temp4->next;
            temp4->next = temp2;
            temp2 = temp4;
            n--;
        }
        temp1->next = temp2;
        return newHead->next;
    }
};

void print_list(ListNode *head)
{
    while(head) {
        cout<<head->val<<",";
        head = head->next;
    }
    cout<<endl;
}
int main()
{
    ListNode x1{3};
    ListNode x2{4,&x1};
    ListNode x3{5,&x2};
    ListNode x4{6,&x3};
    Solution s;
    print_list(s.reverseBetween(&x4, 2,3));
}
