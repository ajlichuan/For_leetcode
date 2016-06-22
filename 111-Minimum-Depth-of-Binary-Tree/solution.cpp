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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        queue<pair<TreeNode*, int>> q;
        
        q.push(make_pair(root,1));
        
        while(!q.empty())
        {
            root = q.front().first;
            int dep = q.front().second;
            q.pop();
            
            if(root->left == NULL && root->right == NULL)
                return dep;
            
            if(root->left != NULL)
                q.push(make_pair(root->left, dep+1));
            
            if(root->right != NULL)
                q.push(make_pair(root->right, dep+1));
        }
        
        return 0;
    }
};