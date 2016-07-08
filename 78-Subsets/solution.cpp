class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        int mlen = pow(2,len);
        vector<vector<int>> res(mlen, vector<int>());
        
        for(int i = 0; i < len; i++)
        {
            for(int j = 1; j < mlen; j++)
            {
                if(((j>>i) & 1) == 1)
                    res[j].push_back(nums[i]);
            }
        }
        
        return res;
    }
};