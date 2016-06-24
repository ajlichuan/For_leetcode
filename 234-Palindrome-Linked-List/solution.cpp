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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        
        ListNode *p1=head->next, *p2=head;
        
        while(p1!=NULL && p1->next!=NULL)
        {
            p1 = p1->next->next;
            p2 = p2->next;
        }
        p2 = p2->next;
        
        ListNode *tmp = p2->next, *ttmp;
        p2->next = NULL;
        while(tmp != NULL)
        {
            ttmp = tmp->next;
            tmp->next = p2;
            p2 = tmp;
            tmp = ttmp;
        }
        
        p1 = head;
        while(p2 != NULL)
        {
            if(p1->val != p2->val)
                return false;
                
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return true;
    }
};