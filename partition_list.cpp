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
    ListNode(int x, ListNode *n = NULL) : val{x}, next{n} {}
};
class Solution {
public:
    static bool lessthan_(int val, int x) {
        return val < x;
    }
    
    static bool greateq_(int val, int x) {
        return !lessthan_(val, x);
    }
    ListNode* partition(ListNode* head, int x) {
        typedef bool (*func_t)(int val, int x);
        func_t cond;
        int i;
        if (!head)
            return NULL;
        ListNode *tempH = head, *tempT = head;
        ListNode *leH = NULL, *leT = NULL, *geH = NULL, *geT = NULL;
        ListNode **newH, **newT;
        if (lessthan_(head->val, x)) {
            i = 1;
            newH = &leH;
            newT = &leT;
            cond = lessthan_;
        } else {
            i = 0;
            newH = &geH;
            newT = &geT;
            cond = greateq_;
        }
        
        while(tempT->next) {
            if (cond(tempT->next->val,x)) {
                tempT = tempT->next;
            } else {
                if (!*newH) {
                    *newH = tempH;
                    *newT = tempT;
                } else {
                    (*newT)->next = tempH;
                    *newT = tempT;
                }
                tempH = tempT->next;
                tempT = tempH;
                (*newT)->next = NULL;
                i = i ^ 1;
                if (i) {
                    newH = &leH;
                    newT = &leT;
                    cond = lessthan_;
                } else {
                    newH = &geH;
                    newT = &geT;
                    cond = greateq_;
                }
            }
        }
        if (!*newH) {
            *newH = tempH;
            *newT = tempT;
        } else {
        cout<<tempH->val<<"sd\n";
            (*newT)->next = tempH;
        cout<<(*newT)->next->val<<"sd\n";
            *newT = tempT;
        }
        cout<<"sd\n";
        if (!geH)
            return leH;
        if (!leH)
            return geH;
        cout<<"sd\n";
        leT->next = geH;
        cout<<"sd\n";
        return leH;
    }
};


void print_list(ListNode *x)
{
    while(x) {
        cout<<x->val<<",";
        x = x->next;
    }
}
int main()
{
    ListNode x {2,NULL};
    ListNode y {3, &x};
    ListNode z {1, &y};
    Solution s;
    print_list(s.partition(&z,3));
}
