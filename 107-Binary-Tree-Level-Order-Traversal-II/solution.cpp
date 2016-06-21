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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*,int>> q;
        
        if(root == NULL) return res;
        
        q.push(make_pair(root,0));
        
        while(!q.empty())
        {
            TreeNode* tt = q.front().first;
            int level = q.front().second;
            
            if(level+1 > res.size())
                res.push_back(vector<int>());

            res[level].push_back(tt->val);
            if(tt->left != NULL)
                q.push(make_pair(tt->left,level+1));
            if(tt->right != NULL)
                q.push(make_pair(tt->right,level+1));

            q.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};