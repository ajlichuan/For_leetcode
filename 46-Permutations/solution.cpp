class Solution {
public:
    int len;
    vector<vector<int>> res;
    
    void helper(int cnt, vector<int>&nums, vector<int>& data, bool is_used[])
    {
        if(cnt == 1)
        {
            for(int i = 0; i < len; i++)
            {
                if(!is_used[i])
                {
                    data.push_back(nums[i]);
                    res.push_back(data);
                    break;
                }
            }
        }
        else
        {
            for(int i = 0; i < len; i++)
            {
                if(!is_used[i])
                {
                    bool tmp_used[len];
                    vector<int> tdata(data);
                    memcpy(tmp_used, is_used, sizeof(tmp_used));
                    
                    tdata.push_back(nums[i]);
                    tmp_used[i] = true;
                    helper(cnt-1, nums, tdata, tmp_used);
                }
            }
            
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        
        bool is_used[len];
        for(int i = 0; i < len; i++)
            is_used[i] = false;
        vector<int> tmp;
        
        helper(len, nums, tmp, is_used);
        
        return res;
    }
};