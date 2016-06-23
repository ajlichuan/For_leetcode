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
    vector<string> res;
public:
    void helper(TreeNode* root,string s)
    {
        s += "->" + to_string(root->val);
        if(root->left == NULL && root->right == NULL)
            res.push_back(s);
        else
        {
            if(root->left != NULL)
                helper(root->left, s);
            if(root->right != NULL)
                helper(root->right, s);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return res;
        
        string st = to_string(root->val);
        
        if(root->left == NULL && root->right == NULL)
            res.push_back(st);
        else
        {
            if(root->left != NULL)
                helper(root->left, st);
            if(root->right != NULL)
                helper(root->right, st);
        }
        
        return res;
    }
};