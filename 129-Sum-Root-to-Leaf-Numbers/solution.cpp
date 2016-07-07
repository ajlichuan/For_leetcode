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
    int sum;
    
    void helper(TreeNode* root, int val)
    {
        val = val*10 + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            sum += val;
        }
        else
        {
            if(root->left != NULL)
                helper(root->left, val);
            if(root->right != NULL)
                helper(root->right, val);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        sum = 0;
        helper(root, 0);
        
        return sum;
    }
};