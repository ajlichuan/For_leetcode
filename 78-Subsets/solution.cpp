class Solution {
private:
    vector<vector<int>> res;
    vector<int> cell;
    int len;
    
    void findsubset(int n, int st, vector<int>& nums)
    {
        for(int i = st; i < len-n+1; i++)
        {
            cell.push_back(nums[i]);
            if(n == 1)
                res.push_back(cell);
            else
                findsubset(n-1,i+1,nums);
            cell.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back(cell);
        len = nums.size();
        if(len == 0) return res;
        
        for(int i = 1; i <= len; i++)
        {
            findsubset(i,0,nums);
        }
        
        return res;
    }
};