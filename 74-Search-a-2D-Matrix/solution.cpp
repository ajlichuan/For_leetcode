class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rlen = matrix.size();
        if(0 == rlen) return false;
        
        int clen = matrix[0].size();
        
        int p1 = 0, p2 = rlen*clen-1,mid;
        
        if(matrix[p1/clen][p1%clen] == target)
            return true;
        if(matrix[p2/clen][p2%clen] == target)
            return true;
            
        while(p1 < p2-1)
        {
            mid = p1 + (p2-p1)/2;
            
            if(matrix[mid/clen][mid%clen] == target)
                return true;
                
            if(matrix[mid/clen][mid%clen] > target)
                p2 = mid;
            else
                p1 = mid;
        }
        
        
        return false;
    }
};