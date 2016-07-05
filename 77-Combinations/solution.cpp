class Solution {
private:
    void helper(int i, int k, int st, int ed, vector<int>& cell, vector<vector<int>>& res)
    {
        if(i == k)
        {
            for(int j = st; j <= ed; j++)
            {
                cell[i] = j;
                res.push_back(cell);
            }
        }
        else
        {
            for(int j = st; j <= ed; j++)
            {
                cell[i] = j;
                helper(i+1, k, j+1, ed+1, cell, res);
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cell(k,0);
        vector<vector<int>> res;
        
        helper(0, k-1, 1, n-k+1, cell, res);
        
        return res;
    }
};