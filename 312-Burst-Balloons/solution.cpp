class Solution {
private:
    int helper(int st, int ed, vector<vector<int>>& mc, vector<int>& nums)
    {
        if(st > ed) return 0;
        
        if(mc[st][ed] != -1) return mc[st][ed];
        
        if(st == ed)
        {
            mc[st][ed] = nums[st] * nums[st+1] * nums[st+2];
            return mc[st][ed];
        }
        
        int maxres = 0;
        
        for(int i = st-1; i <= ed-1; i++)
        {
            maxres = max(maxres, helper(st,i,mc,nums) + nums[st]*nums[i+2]*nums[ed+2] + helper(i+2,ed,mc,nums));
        }
        
        mc[st][ed] = maxres;
        
        return maxres;
    }
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        
        vector<vector<int>> mc(len, vector<int>(len,-1));
        
        return helper(0, len-1, mc, nums);
    }
};