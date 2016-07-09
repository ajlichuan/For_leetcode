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
        vector<int> row;
        if(!root) return res;
        queue<TreeNode*> st;
        
        st.push(root);
        st.push(NULL);
        
        while(true)
        {
            root = st.front();
            st.pop();
            
            if(!root)
            {
                res.push_back(row);
                vector<int>().swap(row);
                if(st.size() == 0)
                    break;
                else
                    st.push(NULL);
            }
            else
            {
                row.push_back(root->val);
                
                if(root->left)
                    st.push(root->left);
                if(root->right)
                    st.push(root->right);
            }
        }
        
        int len = res.size();
        for(int i = 1; i < len; i = i+2)
        {
            reverse(res[i].begin(),res[i].end());
        }
        
        return res;
    }
};