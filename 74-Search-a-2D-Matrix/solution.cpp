class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rlen = matrix.size();
        if(0 == rlen) return false;
        
        int clen = matrix[0].size();
        
        int row,col;
        int p1,p2,mid;
        
        p1 = 0; p2 = rlen-1;
        
        if(matrix[p2][0] == target) return true;
        if(matrix[p2][0] > target)
        {
            if(matrix[p1][0] > target) return false;
            if(matrix[p1][0] == target) return true;
            
            while(p1<p2-1)
            {
                mid = p1 + (p2-p1)/2;
                if(matrix[mid][0] == target)
                    return true;
                if(matrix[mid][0] > target)
                    p2 = mid;
                else
                    p1 = mid;
            }
            row = p1;
        }
        else
            row = p2;
            
        p1 = 0; p2 = clen-1;
        if(matrix[row][p2] == target) return true;
        if(matrix[row][p2] > target)
        {
            while(p1<p2-1)
            {
                mid = p1 + (p2-p1)/2;
                if(matrix[row][mid] == target)
                    return true;
                if(matrix[row][mid] > target)
                    p2 = mid;
                else
                    p1 = mid;
            }
        }
        
        return false;
    }
};