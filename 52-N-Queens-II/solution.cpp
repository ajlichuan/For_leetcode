class Solution {
public:
    int res;
    int row[300];  //行
    int Mdia[300*2]; //主对角线
    int Cdia[300*2]; //副对角线
    int size;

    int totalNQueens(int n) {
        size = n;
        res = 0;
        memset(row,0,sizeof(row));
        memset(Mdia,0,sizeof(Mdia));
        memset(Cdia,0,sizeof(Cdia));
        tNloop(n);
        return res;
    }
    
    void tNloop(int n)
    {
        if(n == 0)
            res ++;
        else
            for(int i = 0; i < size; i++)
            {
                if(n == size || (row[i] == 0 && Mdia[i+n] == 0 && Cdia[i-n+size] == 0))
                {
                    row[i] = 1; Mdia[i+n] = 1; Cdia[i-n+size] = 1; 
                    tNloop(n-1);
                    row[i] = 0; Mdia[i+n] = 0; Cdia[i-n+size] = 0; 
                }
            }
    }
};