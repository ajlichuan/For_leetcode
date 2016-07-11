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
        if(head == NULL || head->next == NULL) return head;
        
        ListNode **it = &head,**p;
        
        while((*it != NULL) && (*it)->val < x)
            it = &((*it)->next);
        if(*it == NULL) return head;
        
        while((*it)->next != NULL)
        {
            while((*it != NULL) && (*it)->val < x)
                it = &((*it)->next);
                
            p = &((*it)->next);
            
            while(*p != NULL && (*p)->val >= x)
                p = &((*p)->next);
            
            if(*p == NULL) return head;
            
            ListNode* tmp = *p;
            *p = (*p)->next;
            tmp->next = *it;
            *it = tmp;
        }
        
        return head;
    }
};