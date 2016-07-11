#include <cmath>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        
        sort(nums.begin(),nums.end());
        
        long res = nums[0] + nums[len-1] + nums[len-2];
        long minerr = abs(target - res);
        
        for(int i = 0; i < len-2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            for(int j = i+1; j < len-1; j++)
            {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                long tmp = nums[i]+nums[j];
                for(int k = j+1; k < len; k++)
                {
                    if((k > j+1 && nums[k] == nums[k-1]) || (nums[k] < target - minerr - tmp)) continue;
                    if(nums[k] > target + minerr - tmp) break;
                    
                    res = tmp + nums[k];
                    minerr = abs(target - res);
                }
            }
        }
        
        return res;
    }
};