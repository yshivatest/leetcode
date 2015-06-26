#include<iostream>
#include "list"
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * Given a sorted linked list, delete ALL nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode x(0);
        x.next = head;
        head = &x;
        while(head->next) {
            ListNode *temp = head->next;
            if (temp->next && temp->next->val == temp->val) {
                //Remove all elements with val
                int val = temp->val;
                head->next = temp->next->next;
                while (head->next && head->next->val == val) 
                    head->next = head->next->next;
            } else {
                head = head->next;
            }
        }
        return x.next;
    }
};
