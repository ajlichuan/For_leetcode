class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
        {
            int tmp[9] = {0};
            for(int j = 0; j < 9; j++)
                if(board[i][j] != '.')
                {
                    if(tmp[board[i][j]-'1'] > 0)
                        return false;
                    tmp[board[i][j]-'1']++;
                }
        }
        
        for(int i = 0; i < 9; i++)
        {
            int tmp[9] = {0};
            for(int j = 0; j < 9; j++)
                if(board[j][i] != '.')
                {
                    if(tmp[board[j][i]-'1'] > 0)
                        return false;
                    tmp[board[j][i]-'1']++;
                }
        }
        
        for(int k = 0; k < 3; k++)
            for(int l=0; l < 3; l++)
            {
                int tmp[9] = {0};
                for(int i = 0; i < 3; i++)
                {
                    for(int j = 0; j < 3; j++)
                        if(board[3*k+i][3*l+j] != '.')
                        {
                            if(tmp[board[3*k+i][3*l+j]-'1'] > 0)
                                return false;
                            tmp[board[3*k+i][3*l+j]-'1']++;
                        }
                }
            }
        return true;
    }
};