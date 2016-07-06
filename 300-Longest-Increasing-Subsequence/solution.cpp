class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max = 0;
        int len = nums.size();
        if(len < 2) return len;
        
        int lis[len] = {0};
        
        for(int i = 0; i < len; i++)
        {
            int tmax = 0;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j] && tmax < lis[j])
                    tmax = lis[j];
            }
            lis[i] = tmax+1;
            if(tmax+1 > max)
                max = tmax+1;
        }
        
        return max;
    }
};