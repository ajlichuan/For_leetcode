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
    TreeNode* buildloop(vector<int>& in, vector<int>& po, int inst, int post, int len)
    {
        if(len < 1) return NULL;
        
        int rootval = po[post+len-1];
        TreeNode* root = new TreeNode(rootval);
        
        int llen;
        for(llen = 0; in[inst+llen] != rootval; llen++);
        
        root->left = buildloop(in, po, inst, post, llen);
        root->right = buildloop(in, po, inst+llen+1, post+llen, len-1-llen);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return buildloop(inorder, postorder, 0, 0, inorder.size());
        
    }
};