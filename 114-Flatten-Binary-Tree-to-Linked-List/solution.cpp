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
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        if(root == NULL) return;
        
        st.push(root);
        TreeNode** right = &root;
        while(!st.empty())
        {
            root = st.top();
            st.pop();
            *right = root;
            right = &(root->right);
            
            if(root->right != NULL)
                st.push(root->right);

            if(root->left != NULL)
            {
                st.push(root->left);
                root->left = NULL;
            }
        }
    }
};