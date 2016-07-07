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
    int mps;
    
    int helper(TreeNode* root)
    {
        if(root == NULL) return 0;
        
        int left = max(helper(root->left),0), right = max(helper(root->right),0);
        if(root->val + left + right > mps)
            mps = root->val + left + right;
        return max(left, right) + root->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        mps = INT_MIN;
        
        return max(helper(root), mps);
    }
};