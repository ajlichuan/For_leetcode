class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return vector<int>();
        int col = matrix[0].size();
        vector<int> res(matrix[0]);
        
        int x = 0, y = col-1, state = 0;
        
        row--;
        
        while(row > 0 && col > 0)
        {       
            for(int i = 0; i < row; i++)
                res.push_back(matrix[++x][y]);
            if(--col <= 0) break;
            
            for(int i = 0; i < col; i++)
                res.push_back(matrix[x][--y]);
            if(--row <= 0) break;
            
            for(int i = 0; i < row; i++)
                res.push_back(matrix[--x][y]);
            if(--col <= 0) break;
            
            for(int i = 0; i < col; i++)
                res.push_back(matrix[x][++y]);
            if(--row <= 0) break;
        }
        
        return res;
    }
};