class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m < 1) return;
        int n = board[0].size();
        
        for(int x = 0; x < m; x++)
        {
            for(int y = 0; y < n; y++)
            {
                int mini = max(0,x-1), maxi = min(x+2,m), minj = max(0,y-1), maxj = min(y+2,n);
                int lives = 0;
                
                for(int i = mini; i < maxi && lives < 4; i++)
                {
                    for(int j = minj; j < maxj; j++)
                    {
                        if(i != x || j != y)
                            if(board[i][j]%2 == 1)
                            {
                                if(++lives > 3)
                                    break;
                            }
                    }
                }
                
                if(lives == 3 || (lives == 2 && board[x][y] == 1))
                    board[x][y] += 2;
            }
        }
        
        for(int x = 0; x < m; x++)
        {
            for(int y = 0; y < n; y++)
            {
                board[x][y] >>= 1;
            }
        }
    }
};