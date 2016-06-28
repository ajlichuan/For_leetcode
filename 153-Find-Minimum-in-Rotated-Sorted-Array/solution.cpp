class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        for(auto n:nums)
        {
            if(n < min) return n;
        }
        return min;
    }
};