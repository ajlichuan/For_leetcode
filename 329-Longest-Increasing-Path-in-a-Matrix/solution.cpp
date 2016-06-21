class Solution {
public:
    int l,h,maxp;
    
public:
    int findpath(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& len)
    {
        int lenp = 1;
        
        if(len[i][j] != -1) return len[i][j];
        
        if(i > 0 && matrix[i-1][j] > matrix[i][j])
        {
            lenp = 1 + findpath(i-1,j,matrix,len);
        }
        
        if(j > 0 && matrix[i][j-1] > matrix[i][j])
        {
            lenp = max(lenp, 1 + findpath(i,j-1,matrix,len));
        }
        
        if(i < h-1 && matrix[i+1][j] > matrix[i][j])
        {
            lenp = max(lenp, 1 + findpath(i+1,j,matrix,len));
        }
        
        if(j < l-1 && matrix[i][j+1] > matrix[i][j])
        {
            lenp = max(lenp, 1 + findpath(i,j+1,matrix,len));
        }
        
        len[i][j] = lenp;
        
        maxp = max(maxp, lenp);
        
        return lenp;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        h = matrix.size();
        if(h == 0) return 0;
        l = matrix[0].size();
        
        vector<int> lencell(l, -1);
        vector<vector<int>> len(h, lencell);
        
        maxp = 0;
        
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < l; j++)
                findpath(i,j,matrix,len);
        }
        
        return maxp;
    }
};