class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int xlen = matrix.size();
        if(xlen == 0) return;
        int ylen = matrix[0].size();
        
        bool fx = false, fy = false;
        
        for(int x = 0; x < xlen; x++)
            if(matrix[x][0] == 0)
            {
                fy = true;
                break;
            }
        
        for(int y = 0; y < ylen; y++)
            if(matrix[0][y] == 0)
            {
                fx = true;
                break;
            }
            
        for(int x = 1; x < xlen; x++)
        {
            for(int y = 1; y < ylen; y++)
            {
                if(matrix[x][y] == 0)
                {
                    matrix[x][0] = 0;
                    matrix[0][y] = 0;
                }
            }
        }
        
        for(int x = 1; x < xlen; x++)
            if(matrix[x][0] == 0)
            {
                for(int y = 1; y < ylen; y++)
                    matrix[x][y] = 0;
            }
        
        for(int y = 1; y < ylen; y++)
            if(matrix[0][y] == 0)
            {
                for(int x = 1; x < xlen; x++)
                    matrix[x][y] = 0;
            }
            
        if(fx)
        {
            for(int y = 0; y < ylen; y++)
                matrix[0][y] = 0;
        }
        
        if(fy)
        {
            for(int x = 0; x < xlen; x++)
                matrix[x][0] = 0;
        }
    }
};