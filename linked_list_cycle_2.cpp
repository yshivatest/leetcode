#include<iostream>
#include "list.h"
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
    ListNode *moveOne(ListNode *p) {
        return p->next;
    }
    
    ListNode* moveTwo(ListNode *p) {
        p = moveOne(p);
        if (p)
            return moveOne(p);
        else
            return NULL;
    }
    
    int listLength(ListNode *head, ListNode *end) {
        int len = 1;
        while(head != end) {
            head = head->next;
            len++;
        }
        return len;
    }
    
    ListNode* moveList(ListNode *head, int len) {
        while(len--) {
            head = head->next;
        }
        return head;
    }
    
    ListNode* cycleBegins(ListNode *head, ListNode *cycle) {
        ListNode *head1 = head;
        ListNode *head2 = cycle->next;
        int x = listLength(head1, cycle);
        int y = listLength(head2, cycle);
        if (x > y) {
            head1 = moveList(head1, x - y);
        } else {
            head2 = moveList(head2, y - x);
        }
        
        //find the intersection
        while(head1 != head2) {
            head1 = head1->next;
            head2 = head2->next;
        }
        return head1;
    }
    
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        if (p1)
            p1 = moveTwo(p1);
        if (p2)
            p2 = moveOne(p2);
        while(p1 && p2) {
            if (p1 == p2) {
                return cycleBegins(head, p1);
            }
            p1 = moveTwo(p1);
            p2 = moveOne(p2);
        }
        return NULL;
    }
};
