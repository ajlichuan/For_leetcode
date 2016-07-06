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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode **it = &l1, *t;
        
        while(*it != NULL && l2 != NULL)
        {
            if((*it)->val < l2->val)
            {
                it = &((*it)->next);
            }
            else
            {
                t = l2->next;
                l2->next = *it;
                *it = l2;
                l2 = t;
            }
        }
        if(*it == NULL)
            *it = l2;
        
        return l1;
    }
};