class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cell(k,0);
        vector<vector<int>> res;
        
        for(int i = 0; i < k; i++)
        {
            cell[i] = i+1;
        }
        res.push_back(cell);
        
        while(true)
        {
            int i;
            for(i = 0; i < k; i++)
            {
                if(++cell[k-1-i] <= n-i)
                    break;
            }
            if(i == k) break;
            for(--i; i>=0; i--)
            {
                cell[k-1-i] = cell[k-2-i]+1;
            }
            
            res.push_back(cell);
        }
        
        return res;
    }
};