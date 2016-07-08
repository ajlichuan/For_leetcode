/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* BST(ListNode* head, int len, ListNode* &last)
    {
        if(len == 0)
        {
            last = head;
            return NULL;
        }
        if(len == 1)
        {
            last = head->next;
            return new TreeNode(head->val);
        }
        
        int lenleft = len/2;
        TreeNode* left = BST(head, lenleft, last);
        TreeNode* root = new TreeNode(last->val);
        root->left = left;
        root->right = BST(last->next, len-1-lenleft, last);
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* it = head;
        int len = 0;
        while(it != NULL)
        {
            len++;
            it = it->next;
        }
        return BST(head, len, head);
    }
};