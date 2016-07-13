class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int xlen = matrix.size();
        if(xlen == 0) return false;
        int ylen = matrix[0].size();
        
        int x = 0, y = ylen-1;
        
        while(x < xlen && y >=0)
        {
            if(target == matrix[x][y])
                return true;
                
            if(target > matrix[x][y])
                x++;
            else
                y--;
        }
        
        return false;
    }
};