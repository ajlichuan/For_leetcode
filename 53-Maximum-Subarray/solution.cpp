class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        
        int maxn = nums[0];
        int sum = nums[0];
        
        for(int i = 1; i < len; i++)
        {
            if(sum < 0)
            {
                if(nums[i] > sum)
                {
                    sum = nums[i];
                    maxn = max(maxn, sum);
                }
            }
            else
            {
                sum += nums[i];
                maxn = max(maxn, sum);
            }
        }
        return maxn;
    }
};