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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if(root == NULL) return res;
        
        queue<pair<TreeNode*, int>> q;
        
        q.push(make_pair(root,0));
        
        while(!q.empty())
        {
            TreeNode* root = q.front().first;
            int level = q.front().second;
            
            q.pop();
            
            if(level + 1 > res.size())
                res.push_back(vector<int>());
            
            res[level].push_back(root->val);
            
            if(root->left != NULL)
                q.push(make_pair(root->left,level+1));
            
            if(root->right != NULL)
                q.push(make_pair(root->right,level+1));
        }
        
        return res;
    }
};