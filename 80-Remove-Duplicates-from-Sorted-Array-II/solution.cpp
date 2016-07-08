class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) return len;
        
        int cnt = 2;
        for(int i = 2; i < len; i++)
        {
            if(nums[cnt-2] != nums[i])
                nums[cnt++] = nums[i];
        }
        
        return cnt;
    }
};