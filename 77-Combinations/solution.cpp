class Solution {
private:
    vector<vector<int>> res;
    int maxk;

    void helper(int k, int st, int ed, vector<int>& cell)
    {
        if(maxk == k)
        {
            for(int i = st; i <= ed; i++)
            {
                cell[k-1] = i;
                res.push_back(cell);
            }
        }
        else
        {
            for(int i = st; i <= ed - maxk + k; i++)
            {
                cell[k-1] = i;
                helper(k+1,i+1,ed,cell);
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cell(k,0);
        maxk = k;

        helper(1, 1, n, cell);
        
        return res;
    }
};