class Solution {
private:
    int xlen;
    int ylen;
    
    int spread(int x, int y, vector<vector<char>>& grid)
    {
        if(grid[x][y] == '0') return 0;
        
        grid[x][y] = '0';
        if(x>0) spread(x-1,y,grid);
        if(y>0) spread(x,y-1,grid);
        if(x<xlen-1) spread(x+1,y,grid);
        if(y<ylen-1) spread(x,y+1,grid);
        
        return 1;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        xlen = grid.size();
        
        if(xlen == 0) return 0;
        
        ylen = grid[0].size();
        
        int cnt = 0;
        for(int x = 0; x < xlen; x++)
            for(int y = 0; y < ylen; y++)
                cnt += spread(x,y,grid);
        
        return cnt;
    }
};