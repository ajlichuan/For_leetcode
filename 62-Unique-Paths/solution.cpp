class Solution {
public:
    int uniquePaths(int m, int n) {
        int st[m];
        
        for(int i = 0; i < m; i++)
        {
            st[i] = 1;
        }
        
        for(int i = 1; i < n; i++)
        {
            for(int j = m-2; j >= 0; j--)
            {
                st[j] = st[j] + st[j+1];
            }
        }
        
        return st[0];
    }
};