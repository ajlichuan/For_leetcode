class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) return len;
        
        int cnt = 1;
        bool flag = false;
        for(int i = 1; i < len; i++)
        {
            if(nums[i-1] == nums[i])
            {
                if(flag) continue;
                flag = true;
            }
            else
            {
                flag = false;
            }
            nums[cnt++] = nums[i];
        }
        
        return cnt;
    }
};