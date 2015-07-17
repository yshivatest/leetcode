/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/
#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *n) : val{x}, next{n} {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!k || !head)
            return head;
        int x = k;
        ListNode *temp1 = head, *temp2 = head;
        while(x && temp2->next) {
            temp2 = temp2->next;
            x--;
        }
        if (x == 0) {
            while(temp2->next) {
                temp2 = temp2->next;
                temp1 = temp1->next;
            }
            temp2->next = head;
            head = temp1->next;
            temp1->next = NULL;
            return head;
        }
        int length = k - x + 1;
        return rotateRight(head, k % length);
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
    ListNode x1{1,NULL};
    ListNode x2{2,&x1};
    ListNode x3{3,&x2};
    ListNode x4{4,&x3};
    ListNode x5{5,&x4};
    Solution s;
    print_list(s.rotateRight(&x5, 7));
}
