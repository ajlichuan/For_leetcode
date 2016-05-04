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
    bool hasCycle(ListNode *head) {
        ListNode *fast, *slow;
        int cnt = 0;
        int lim = 2;
        
        fast = head;
        slow = head;
        
        do
        {
            if(fast == NULL) return false;
            
            if(cnt == lim)
            {
                cnt = 1;
                lim = lim * 2;
                slow = fast;
            }
            else
                cnt ++;
            
            fast = fast->next;
            
        } while(fast != slow);
        
        return true;
    }
};