class Solution {
private:
    vector<vector<int>> res;
    vector<int> cell;
private:
    void helper(int cnt, int target, vector<int>& cand)
    {
        int num = 0;
        int iend = 0;
        for(int i = cnt; i >= iend; i--)
        {
            if(num == cand[i]) continue;
            num = cand[i];
            if(num <= target)
            {
                cell.push_back(num);
                if(num < target)
                    helper(i-1, target-num, cand);
                else
                    res.push_back(cell);
                cell.pop_back();
            }
            iend = max(target/num-1,0);
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();
        
        if(len < 1) return res;
        
        sort(candidates.begin(),candidates.end());
        
        helper(len-1, target, candidates);
        
        return res;
    }
};