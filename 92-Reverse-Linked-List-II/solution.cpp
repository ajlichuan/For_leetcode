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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode begin(0);
        begin.next = head;
        
        stack<ListNode*> st;
        ListNode *first;
        
        head = &begin;
        
        n = n - m + 1;
        while(--m) 
        {
            head = head -> next;
        }
        
        first = head -> next;
        
        int tmp = n;
        while(tmp--)
        {
            st.push(first);
            first = first -> next;
        }
        
        while(n--)
        {
            head -> next = st.top();
            st.pop();
            head = head -> next;
        }
        
        head -> next = first;
        
        return begin.next;
    }
};