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
    bool res = true;

public:
    int Treedep(TreeNode* root)
    {
        if(res)
        {
            if(root == NULL)
            {
                return 0;
            }
            else
            {
                int tl, tr;
                
                tl = Treedep(root->left)+1;
                tr = Treedep(root->right)+1;
                
                if(abs(tl - tr) > 1)
                    res = false;
                
                return max(tl, tr);
            }
        }
        else
            return -1;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        Treedep(root);
        
        return res;
    }
};