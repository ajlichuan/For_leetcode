class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> row;
        
        for(int i = 0; i < numRows; i++)
        {
            if(i == 0)
            {
                row.push_back(1);
                res.push_back(row);
                row.clear();
            }
            else
            {
                for(int j = 0; j < i+1; j++)
                {
                    if(j == 0 || j == i)
                        row.push_back(1);
                    else
                        row.push_back(res[i-1][j-1]+res[i-1][j]);
                }
                res.push_back(row);
                row.clear();
            }
        }
        
        return res;
    }
};