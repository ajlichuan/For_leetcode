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
    ListNode* insertionSortList(ListNode* head) {
        if(NULL == head || NULL == head->next) return head;
        
        ListNode **p, *to_sort = head->next, *t;
        head->next = NULL;
        while(to_sort != NULL)
        {
            p = &head;
            
            while((*p) != NULL && (*p)->val < to_sort->val)
                p = &((*p)->next);
            
            t = to_sort->next;
            to_sort->next = *p;
            *p = to_sort;
            to_sort = t;
        }
        
        return head;
    }
};