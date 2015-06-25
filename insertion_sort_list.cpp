#include<iostream>
#include<climits>
#include "list.h"
using namespace std;

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode x(INT_MIN), *p = &x;
        p->next = head;
        while(p->next) {
            if (p->next->val < p->val) {
                ListNode *temp = p->next;
                p->next = temp->next;
                temp->next = NULL;
                
                //Insert temp in the sorted list
                ListNode *h = &x;
                while(h->next->val < temp->val)
                    h = h->next;
                temp->next = h->next;
                h->next = temp;
            } else {
                p = p->next;
            }
        }
        return x.next;
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
	print_list(s.insertionSortList(&x5));
}
