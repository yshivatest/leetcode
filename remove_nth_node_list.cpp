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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *runner1 = head, *runner2 = head;
        while(n--)
            runner2 = runner2->next;
        if (!runner2)
            return head->next;
        while(runner2->next) {
            runner2 = runner2->next;
            runner1 = runner1->next;
        }
        runner1->next = runner1->next->next;
        return head;
    }
};
