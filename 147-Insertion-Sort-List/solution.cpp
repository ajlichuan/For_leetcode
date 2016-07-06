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
        
        ListNode **p, *to_sort = head->next, *t1, *t2;
        head->next = NULL;
        while(to_sort != NULL)
        {
            p = &head;
            
            while((*p) != NULL && (*p)->val < to_sort->val)
                p = &((*p)->next);
            
            t1 = *p;
            *p = to_sort;
            t2 = to_sort->next;
            to_sort->next = t1;
            to_sort = t2;
        }
        
        return head;
    }
};