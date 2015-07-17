/*
Reverse Nodes in k-Group 
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverselist(ListNode *h) {
        ListNode *newh = NULL, *temp;
        while(h) {
            temp = h->next;
            h->next = newh;
            newh = h;
            h = temp;
        }
        return newh;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode temp(INT_MIN), *p=&temp;
        p->next = head;
        
        
        ListNode *prev = p;
        ListNode *start, *end, *next;
        
        while(1) {
            start = prev->next;
            next = start;
            int j = k-1;
            //find next
            while(j && next) {
                j--;
                next = next->next;
            }
            if (j || !next) {
                //done reversing return temp->next
                return temp.next;
            }
            end = next;
            next = end->next;
            end->next = NULL;
            //reverse list from start to end
            prev->next = reverselist(start);
            start->next = next;
            //new prev is old start
            prev = start;
            
        }
        
    }
};
