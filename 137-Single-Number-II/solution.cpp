class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        
        for(auto i : nums)
        {
            b = ~a & (i ^ b);
            a = ~b & (i ^ a);
        }
        
        return a ^ b;
    }
};