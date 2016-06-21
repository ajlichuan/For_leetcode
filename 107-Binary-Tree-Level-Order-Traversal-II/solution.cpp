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
        vector<int> tmp;
        queue<TreeNode*> q;
        
        if(root == NULL) return res;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeNode* tt = q.front();
            if(tt == NULL)
            {
                res.push_back(tmp);
                if(q.size() != 1)
                    q.push(NULL);
                tmp.clear();
            }
            else
            {
                tmp.push_back(tt->val);
                if(tt->left != NULL)
                    q.push(tt->left);
                if(tt->right != NULL)
                    q.push(tt->right);
            }
            q.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};