class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return nums;
        
        int next[len];
        int sum[len] = {0};
        memset(next, -1, sizeof(next));
        
        sort(nums.begin(), nums.end());
        for(int i=len-1; i >=0; i--)
        {
            for(int j = i+1; j < len; j++)
            {
                if(nums[j] % nums[i] == 0)
                {
                    if(sum[i] < sum[j] + 1)
                    {
                        sum[i] = sum[j]+1;
                        next[i] = j;
                    }
                }
            }
        }
        
        int tar = 0;
        if(nums[0] != 1)
        {
            for(int i = 1; i < len; i++)
            {
                if(sum[i] > sum[tar])
                {
                    tar = i;
                }
            }
        }
        
        vector<int> res{nums[tar]};
        
        while(next[tar] != -1)
        {
            tar = next[tar];
            res.push_back(nums[tar]);
        }
        
        return res;
    }
};