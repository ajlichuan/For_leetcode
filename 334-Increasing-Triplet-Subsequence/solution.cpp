class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        
        int s1, s2;
        s1 = INT_MAX;
        s2 = INT_MAX;
        for(auto n:nums)
        {
            if(n <= s1)
                s1 = n;
            else if(n <= s2)
                s2 = n;
            else
                return true;
        }
        return false;
    }
};