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
public:
    void robloop(TreeNode* root, int &rob, int &urob)
    {
        int lrob=0,lurob=0,rrob=0,rurob=0;
        
        if(root->left != NULL)
            robloop(root->left, lrob, lurob);
        
        if(root->right != NULL)
            robloop(root->right, rrob, rurob);
        
        rob = lurob + rurob + root->val;
        urob = max(lurob, lrob) + max(rurob, rrob);
    }

public:
    int rob(TreeNode* root) {
        if(root != NULL)
        {
            int rob = 0, urob = 0;
            robloop(root, rob, urob);
            
            return max(rob, urob);
        }
        return 0;
    }
};