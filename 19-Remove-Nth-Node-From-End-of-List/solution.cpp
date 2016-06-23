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
        ListNode **p1 = &head, *p2 = head;
        
        int i = n;
        while(i--)
            p2 = p2->next;
        
        while(p2 != NULL)
        {
            p1 = &((*p1)->next);
            p2 = p2->next;
        }
        
        *p1 = (*p1)->next;
        
        return head;
    }
};