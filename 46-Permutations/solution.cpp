class Solution {
public:
    int len;
    vector<vector<int>> res;
    
    void helper(int cnt, vector<int>&nums)
    {
        if(cnt == len-1)
        {
            res.push_back(nums);
        }
        else
        {
            for(int i = cnt; i < len; i++)
            {
                swap(nums[cnt],nums[i]);
                helper(cnt+1, nums);
                swap(nums[i],nums[cnt]);
            }
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();

        helper(0, nums);
        
        return res;
    }
};