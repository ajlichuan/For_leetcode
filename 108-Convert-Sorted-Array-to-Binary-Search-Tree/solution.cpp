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
    vector<int> SA;
public:
    TreeNode* loop(int st, int ed) {
        if(ed >= st)
        {
            int mid = (st+ed+1)/2;
            TreeNode* root = new TreeNode(SA[mid]);
            
            root->left = loop(st, mid-1);
            root->right = loop(mid+1, ed);
            
            return root;
        }
        return NULL;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        
        SA = nums;

        return loop(0, nums.size()-1);
    }
};