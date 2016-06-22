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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        
        stack<TreeNode*> st;
        
        st.push(root->left);
        st.push(root->right);
        
        while(!st.empty())
        {
            TreeNode *l, *r;
            l = st.top(); st.pop();
            r = st.top(); st.pop();
            
            if(l == NULL || r == NULL)
                if(l != r)
                    return false;
                else
                    continue;
            
            if(l->val != r->val)
                return false;
            
            st.push(l->left);
            st.push(r->right);
            st.push(l->right);
            st.push(r->left);
        }
        
        return true;
    }
};