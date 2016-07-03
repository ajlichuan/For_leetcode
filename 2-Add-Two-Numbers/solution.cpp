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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int pls = 0;
        ListNode *head = l1, *p;
        while(NULL != l1 && NULL != l2)
        {
            int tmp = l1->val + l2->val + pls;
            if(tmp >= 10)
            {
                tmp -= 10;
                pls = 1;
            }
            else
                pls = 0;
            
            l1->val = tmp;
            p = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        p->next = NULL == l1 ? l2 : l1;
        
        while(NULL != p->next && 1 == pls)
        {
            if(p->next->val < 9)
            {
                p->next->val = p->next->val + 1;
                pls = 0;
            }
            else
                p->next->val = 0;
            
            p = p->next;
        }
        
        if(1 == pls)
        {
            ListNode* LN = new ListNode(1);
            p->next = LN;
        }
        
        return head;
    }
};