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

    ListNode* partition(ListNode* head, int x) {
        ListNode a(INT_MIN), b(INT_MIN);
        ListNode *leH = &a, *geH = &b, *leT = &a, *geT = &b;
        if (!head)
            return head;
        while(head) {
            ListNode *temp = head;
            head = head->next;
            if (temp->val < x) {
                leT->next = temp;
                temp->next = NULL;
                leT = temp;
            } else {
                geT->next = temp;
                temp->next = NULL;
                geT = temp;
            }
        }
        leH = leH->next;
        geH = geH->next;
        if (!geH)
            return leH;
        if (!leH)
            return geH;
        leT->next = geH;
        return leH;
    }
};
