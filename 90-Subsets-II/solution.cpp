class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>());
        int len = nums.size();
        int rlen;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < len; i++)
        {
            int st = 0;
            if(i != 0 && nums[i] == nums[i-1])
                st = rlen;
                
            rlen = res.size();
            for(int j = st; j < rlen; j++)
            {
                vector<int> tmp(res[j]);
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        
        return res;
    }
};