class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return len;
        
        int cnt = 0;
        
        for(int i = 1; i < len; i++)
        {
            if(nums[i] != nums[i-1])
                nums[++cnt] = nums[i];
        }
        
        return cnt+1;
    }
};