class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return;
        
        int i = len-2;
        
        for(;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
                break;
        }
        if(i == -1)
            sort(nums.begin(),nums.end());
        else
        {
            int prs = len-1;
            while(nums[i]>=nums[prs]) prs--;
            
            swap(nums[i],nums[prs]);
            
            auto it=nums.begin();
            while(i >= 0)
                it++,i--;
            
            sort(it,nums.end());
        }
    }
};