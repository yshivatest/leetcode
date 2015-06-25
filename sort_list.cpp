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
#include "list.h"
class Solution {
public:
    struct Whatever {
        ListNode *a, *b;
        int al, bl;
    };
    // x & y are supposed to be NULL terminated
    ListNode* mergeList(ListNode *x, ListNode *y) {
        ListNode head(0), *h = &head;
        while(x && y) {
            if (x->val <= y->val) {
                h->next = x;
                x = x->next;
                h = h->next;
                h->next = NULL;
            } else {
                h->next = y;
                y = y->next;
                h = h->next;
                h->next = NULL;
            }
        }
        if (!x && !y)
            return head.next;
        if (!x) {
            h->next = y;
            return head.next;
        }
        h->next = x;
        return head.next;
    }
    
    //split a given list into two halves
    // len is always > 1
    Whatever splitList(ListNode *x, int len) {
        Whatever t;
        t.a = x;
        t.al = len/2;
        t.bl = (len - len/2);
        //move x t.al - 1 times and set t.b = x->next & set x->next = NULL
        len = t.al - 1;
        while(len--) 
            x = x->next;
        t.b = x->next;
        x->next = NULL;
        return t;
    }
    
    int listLength(ListNode *x) {
        int len = 0;
        while(x) {
            len++;
            x = x->next;
        }
        return len;
    }
    
    ListNode* sortList_int(ListNode *head, int len) {
        if (len <= 1)
            return head;
        Whatever x = splitList(head, len);
        return mergeList(sortList_int(x.a, x.al), sortList_int(x.b, x.bl));
        
    }
    ListNode* sortList(ListNode* head) {
        return sortList_int(head, listLength(head));
    }
};

int main()
{
    ListNode x1{1,NULL};
    ListNode x2{2,&x1};
    ListNode x3{3,&x2};
    ListNode x4{4,&x3};
    ListNode x5{5,&x4};
    Solution s;
    print_list(s.sortList(&x5));
}
