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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> st;
        
        st.push(root);
        int len = 1;
        bool l2r = true;
        
        while(len > 0)
        {
            vector<int> row(len);
            
            for(int i = 0; i < len; i++)
            {
                root = st.front();
                st.pop();
                
                int index = l2r ? i : len-1-i;
                row[index] = root->val;
                
                if(root->left)
                    st.push(root->left);
                if(root->right)
                    st.push(root->right);
            }
            
            res.push_back(row);
            
            len = st.size();
            
            l2r = !l2r;
        }
        
        return res;
    }
};