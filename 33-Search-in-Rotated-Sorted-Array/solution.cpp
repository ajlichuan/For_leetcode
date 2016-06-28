class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return -1;
        
        int min = nums[0];
        if(target == min) return 0;
        
        
        if(target > min)
        {
            for(int i = 1; i < len; i++)
            {
                if(nums[i] == target) return i;
                if(nums[i] > target || nums[i] < min) return -1;
            }
        }
        else
        {
            int i = 1;
            while(i < len && nums[i] > min) i++;
            while(i < len && nums[i] <= target)
                if(nums[i++] == target)
                    return i-1;
        }
        
        return -1;
    }
};