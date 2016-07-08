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
    TreeNode* BST(ListNode* &head, int len)
    {
        if(len == 0)
        {
            return NULL;
        }
        if(len == 1)
        {
            int val = head->val;
            head = head->next;
            return new TreeNode(val);
        }
        
        int lenleft = len/2;
        TreeNode* left = BST(head, lenleft);
        TreeNode* root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = BST(head, len-1-lenleft);
        
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
        return BST(head, len);
    }
};