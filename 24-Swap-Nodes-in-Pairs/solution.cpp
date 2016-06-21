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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode ret(0), *tmp;
        
        ret.next = head;
        
        tmp = &ret;
        
        while(tmp->next != NULL && tmp->next->next != NULL)
        {
            ListNode *ttmp;
            
            ttmp = tmp->next;
            tmp->next = ttmp->next;
            ttmp->next = tmp->next->next;
            tmp->next->next = ttmp;
            tmp = ttmp;
        }
        
        return ret.next;
    }
};