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
    bool hasCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        while(p1 && p2) {
            p1 = p1->next;
            if (p1) {
                p1 = p1->next;
            } else {
                return false;
            }
            p2 = p2->next;
            if (p1 == p2 && p1 != NULL)
                return true;
        }
        return false;
    }
};
