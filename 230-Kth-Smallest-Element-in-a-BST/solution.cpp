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
    int cnt;
    int res;
    
public:
    void kthloop(TreeNode* root)
    {
        if(cnt > 0) 
        {
            if(root->left != NULL)
                kthloop(root->left);
        
            if(cnt == 1) res = root->val;
            cnt--;
            
            if(root->right != NULL)
                kthloop(root->right);
        }
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        
        kthloop(root);
        
        return res;
    }
};