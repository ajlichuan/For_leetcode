class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        
        auto it = nums.begin();
        for(int i = 0; i <len-k; i++,++it);
        
        reverse(nums.begin(),it);
        reverse(it,nums.end());
        reverse(nums.begin(),nums.end());
    }
};