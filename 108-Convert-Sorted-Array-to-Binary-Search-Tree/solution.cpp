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
    TreeNode* loop(int st, int ed, vector<int>& nums) {
        if(ed >= st)
        {
            int mid = (st+ed+1)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            
            root->left = loop(st, mid-1, nums);
            root->right = loop(mid+1, ed, nums);
            
            return root;
        }
        return NULL;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return loop(0, nums.size()-1, nums);
    }
};