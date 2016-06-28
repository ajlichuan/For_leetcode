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
    int maxdep;
    vector<int> res;
    
    void helper(TreeNode *root, int dep)
    {
        if(root != NULL)
        {
            if(dep > maxdep)
            {
                res.push_back(root->val);
                maxdep++;
            }
            helper(root->right, dep+1);
            helper(root->left, dep+1);
        }
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return vector<int>();
        
        maxdep = 0;
        
        helper(root, 1);
        
        return res;
    }
};