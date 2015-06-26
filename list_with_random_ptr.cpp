/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *newHead = NULL, *temp = head, *prev = NULL, *tempNext = NULL;
        //Construct new list
        while(temp) {
            RandomListNode *x = new RandomListNode(temp->label);
            x->random = temp;
            if (!prev) {
                newHead = x;
                prev = x;
            } else {
                prev->next = x;
                prev = x;
            }
            tempNext = temp->next;
            temp->next = x;
            temp = tempNext;
        }
        //find all new random pointers
        temp = newHead;
        RandomListNode *origtemp;
        while(temp) {
            origtemp = temp->random;
            if (origtemp->random)
                origtemp->random = origtemp->random->next; 
            temp = temp->next;
        }
        
        //find all old random pointers and put them in orignext
        temp = newHead;
        while(temp) {
            origtemp = temp->random;
            if (origtemp->random)
                origtemp->next = origtemp->random->random;
            else
                origtemp->next = NULL;
            temp = temp->next;
        }
        
        //move random pointers and construct the old list
        RandomListNode *temp1 = head, *temp2 = newHead, *temp3;
        while(temp2) {
            //modify temp2->random, temp1->random, temp1->next
            
            //Exchange temp1->random and temp1->next (now temp1->random points to the right orig val & temp1->next points to new random pointer)
            temp3 = temp1->random;
            temp1->random = temp1->next;
            temp1->next = temp3;
            
            //Put temp1->next in temp2->random
            temp2->random = temp1->next;
            
            if(temp2->next)
                temp1->next = temp2->next->random;
            else
                temp1->next = NULL;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return newHead;
    }
};
