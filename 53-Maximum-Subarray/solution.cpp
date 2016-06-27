class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        
        int maxn = nums[0];
        int sum = nums[0];
        
        for(int i = 1; i < len; i++)
        {
            sum = max(sum+nums[i], nums[i]);
            maxn = max(sum, maxn);
        }
        return maxn;
    }
};