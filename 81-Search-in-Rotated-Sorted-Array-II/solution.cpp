class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return false;
        
        int min = nums[0];
        if(target == min) return true;
        
        
        if(target > min)
        {
            for(auto n:nums)
            {
                if(n == target) return true;
                if(n > target || n < min) return false;
            }
        }
        else
        {
            int i = 1;
            while(i < len && nums[i] >= min) i++;
            while(i < len && nums[i] <= target)
                if(nums[i++] == target)
                    return true;
        }
        
        return false;
    }
};