class Solution {
private:
    vector<vector<int> >res;
    int len;
    
public:
    void helper(int cnt, vector<int> nums) {
        if (cnt == len-1) {
            res.push_back(nums);
            return;
        }
        for (int i = cnt; i < len; i++)
        {
            if (cnt == i || nums[cnt] != nums[i])
            {
                swap(nums[cnt], nums[i]);
                helper(cnt+1, nums);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        len = nums.size();
        
        sort(nums.begin(), nums.end());
        
        helper(0, nums);
        
        return res;
    }
};