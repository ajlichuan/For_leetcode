class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int max = nums[0];
        
        for(int i = 0; i < len; i++)
        {
            if(i > max)
                return false;

            if(i+nums[i] > max)
                max = i+nums[i];
        }
        
        return true;
    }
};