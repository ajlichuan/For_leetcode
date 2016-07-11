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
            
            int j = i+1, k = len-1;
            while(j<k)
            {
                int cursum = nums[i]+nums[j]+nums[k];
                if(abs(cursum-target) < minerr)
                {
                    res = cursum;
                    minerr = abs(target-res);
                    if(minerr == 0) return res;
                }
                
                if(cursum > target)
                    k--;
                else
                    j++;
            }
        }
        
        return res;
    }
};