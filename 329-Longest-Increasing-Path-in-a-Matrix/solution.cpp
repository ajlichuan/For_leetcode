class Solution {
public:
    int l,h,maxp;
    
public:
    int findpath(int i, int j, vector<vector<int>>& matrix, int *len)
    {
        int lenp = 1;
        
        if(len[i*l+j] != -1) return len[i*l+j];
        
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
        
        len[i*l+j] = lenp;
        
        maxp = max(maxp, lenp);
        
        return lenp;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        h = matrix.size();
        if(h == 0) return 0;
        l = matrix[0].size();
        
        int len[h*l];
        memset(len,-1,sizeof(len));
        
        maxp = 0;
        
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < l; j++)
                findpath(i,j,matrix,len);
        }
        
        return maxp;
    }
};