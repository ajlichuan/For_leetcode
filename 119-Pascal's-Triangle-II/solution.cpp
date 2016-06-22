class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        
        if(rowIndex < 0) return res;
        
        res.push_back(1);
        
        for(int i = 0; i < rowIndex; i++)
        {
            res.push_back(1);
            int tmp = 1;
            
            for(int j = 1; j < i+1; j++)
            {
                res[j] += tmp;
                tmp = res[j] - tmp;
            }
        }
        
        return res;
    }
};