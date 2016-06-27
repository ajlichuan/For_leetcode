class Solution {
private:
    vector<vector<int>> res;
    int fac[9] = {9,17,24,30,35,39,42,44,45};

    void helper(int st, int k, int n, vector<int>& r)
    {
        if(k == 1)
        {
            if(n >= st)
            {
                r.push_back(n);
                res.push_back(r);
            }
        }
        else
        {
            int tmp = min(st + (n-st)/k,9);
            st = max(st, n-fac[k-2]);
            for(int i = st; i<tmp; i++)
            {
                vector<int> tmp(r);
                tmp.push_back(i);
                helper(i+1, k-1, n-i, tmp);
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>9 || n > fac[k-1]) return res;
        vector<int> a;
        helper(1, k, n, a);
        
        return res;
    }
};