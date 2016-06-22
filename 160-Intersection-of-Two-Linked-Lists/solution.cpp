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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> s;
        
        while(headA != NULL || headB != NULL)
        {
            if(headA != NULL)
            {
                if(s[headA] != 0)
                    return headA;
                
                s[headA] = 1;
                headA = headA->next;
            }
            
            if(headB != NULL)
            {
                if(s[headB] != 0)
                    return headB;
                
                s[headB] = 1;
                headB = headB->next;
            }
        }
        return NULL;
    }
};