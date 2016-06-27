class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        
        auto it = nums.begin();
        for(int i = 0; i <len-k; i++,++it);
        
        vector<int> res(it, nums.end());
        res.insert(res.end(),nums.begin(),it);
        
        nums.swap(res);
    }
};