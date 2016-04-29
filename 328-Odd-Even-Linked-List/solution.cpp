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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd, *even, *now, *even_st;
        bool flag;
        
        if(head == NULL || head -> next == NULL)
            return head;
            
        odd = head;
        even = head -> next;
        even_st = even;
        now = even -> next;
        flag = true;
        
        while(now != NULL)
        {
            if(flag)
            {
                odd -> next = now;
                odd = now;
            }
            else
            {
                even -> next = now;
                even = now;
            }
            flag = !flag;
            now = now -> next;
        }
        
        odd -> next = even_st;
        even -> next = NULL;
        
        return head;
    }
};