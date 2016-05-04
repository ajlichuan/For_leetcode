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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;
        
        int cnt = 1, lim = 1;
        fast = head;
        slow = head;
        
        do{
            if(fast == NULL) return NULL;
            
            if(cnt == lim)
            {
                cnt = 1;
                lim = lim * 2;
                slow = fast;
            }
            else
            {
                cnt ++;
            }
            fast = fast -> next;
            
        } while(slow != fast);
        
        fast = head;
        
        for(int i = 0; i < cnt; i++)
            fast = fast -> next;
            
        slow = head;
        
        while(slow != fast)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return fast;
    }
};