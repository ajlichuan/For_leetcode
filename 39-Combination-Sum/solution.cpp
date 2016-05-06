class Solution {
public:
    vector<vector<int>> res;
public:
    void cSloop(vector<int>& cand, int target, vector<int>& candcnt, int i)
    {
        if(i == 0)
        {
            if(target % cand[0] == 0)
            {
                candcnt[i] = target / cand[0];
                vector<int> tmp;
                
                for(int c = 0; c < candcnt.size(); c++)
                {
                    for(int j = 0; j < candcnt[c]; j++)
                    tmp.push_back(cand[c]);
                }
                
                res.push_back(tmp);
            }
        }
        else
        {
            for(int j = 0; j <= target/cand[i]; j++)
            {
                candcnt[i] = j;
                cSloop(cand, target-j*cand[i], candcnt, i-1);
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> candcnt(candidates.size(),0);
        
        sort(candidates.begin(),candidates.end());
        cSloop(candidates, target, candcnt, candidates.size()-1);
        
        return res;
    }
};