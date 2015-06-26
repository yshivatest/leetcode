/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 * Another try to solve the same problem
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return head;

        RandomListNode x(0), *h1 = head, *h2 = &x;
        while(head) {
            RandomListNode *temp = new RandomListNode(head->val);
            temp->random = head;
            auto temp2 = head->next;
            head->next = temp;
            head = temp2;
            h2->next = temp;
            h2 = temp;
        }
        h2 = x.next;
        h1 = head;
        // change h1 random to point to new random
        while(h2) {
            h1 = h2->random;
            if (h1->random)
                h1->random = h1->random->next;
            h2 = h2->next;
        }

        //Now h1->random points to new random ptrs
        h1 = head;
        h2 = x.next;
        //Now point h1->next to old random ptrs
        while(h2) {
            auto temp = h2->random;
            if (temp->random)
                temp->next = temp->random->random;
	    else
		temp->next = NULL;
            h2 = h2->next;
        }
        //Now all the h1->next point to old random ptrs
        //h1->random point to new random ptrs
        //h2->random points to their corresponding nodes in h1
        h1 = head;
        h2 = x.next;

        while(h2) {
            auto temp = h2->random;
            swap(temp->next, temp->random);
            h2->random = temp->next;
            h2 = h2->next;
            if (h2)
                temp->next = h2->random;
            else
                temp->next = NULL;
        }
        return x.next;
    }
};
