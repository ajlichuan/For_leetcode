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
    vector<vector<int>> res;
    TreeNode* rt;
    void findpath(int path, int cnt)
    {
        vector<int> cell(cnt);
        TreeNode* root = rt;
        for(int i = 0; i < cnt; i++)
        {
            cell[i] = root->val;
            root = ((path & 1) == 0) ? root->left : root->right;
            path >>= 1;
        }
        res.push_back(cell);
    }
    
    void helper(TreeNode* root, int sum, int path, int cnt)
    {
        int tmp = sum - root->val;
        
        if(tmp == 0 && root->left == NULL && root->right == NULL)
            findpath(path, cnt+1);

        if(root->left != NULL)
        {
            helper(root->left, tmp, path, cnt+1);
        }
        if(root->right != NULL)
        {
            helper(root->right, tmp, path + (1<<cnt), cnt+1);
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) return res;
        rt = root;
        
        helper(root, sum, 0, 0);
        
        return res;
    }
};