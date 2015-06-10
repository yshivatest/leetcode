#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *n = NULL): val(x), next(n) {}
};
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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        int x = 0;
        ListNode *runner1 = head, *runner2 = head->next;
        while(runner2 && runner2->next) {
            runner2 = runner2->next->next;
            runner1 = runner1->next;
        }
        ListNode *temp1 = head, *temp2 = NULL, *temp3, *temp4;
        temp2 = runner1->next;
        runner1->next = NULL;
        
        //reverse list from temp2
        ListNode *temp5 = temp2, *newH = NULL, *temp6;

        while(temp5) {
            temp6 = temp5->next;
            temp5->next = newH;
            newH = temp5;
            temp5 = temp6;
        }
        temp2 = newH;
        //merge lists
        while(temp1 && temp2) {
            temp3 = temp1->next;
            temp4 = temp2->next;
            
            temp1->next = temp2;
            temp2->next = temp3;
            
            temp1 = temp3;
            temp2 = temp4;
        }
    }
};


void print_list(ListNode *x)
{
    while(x) {
        cout<<x->val<<",";
        x = x->next;
    }
    cout<<endl;
}
int main()
{
    ListNode x1(5,NULL);
    ListNode x2(4,&x1);
    ListNode x3(3,&x2);
    ListNode x4(2,&x3);
    ListNode x5(1,&x4);

    Solution s;
    s.reorderList(&x5);
    print_list(&x5);
}
