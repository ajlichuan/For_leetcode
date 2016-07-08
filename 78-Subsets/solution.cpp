class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cell;
        res.push_back(cell);
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            res.push_back({nums[i]});
            int tlen = res.size();
            for(int j = 1; j < tlen-1; j++)
            {
                vector<int> it(res[j]);
                it.push_back(nums[i]);
                res.push_back(it);
            }
        }
        
        return res;
    }
};