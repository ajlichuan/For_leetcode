class Solution {
public:
    int numSquares(int n) {
        vector<int> data(n+1);
        data[1] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            int minr = INT_MAX;
            for(int j = 1; j*j<=i; j++)
            {
                if(j*j == i)
                {
                    minr = 1;
                    break;
                }
                minr = min(minr, data[i-j*j]+1);
            }
            data[i] = minr;
        }
        
        return data[n];
    }
};