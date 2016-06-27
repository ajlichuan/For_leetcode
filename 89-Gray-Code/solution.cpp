class Solution {
public:
    vector<int> grayCode(int n) {
        if(n < 0) return vector<int>();
        if(n == 0) return {0};
        
        vector<int> res(pow(2,n),0);
        
        res[1] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            int lim = pow(2,i-1);
            for(int j = 0; j < lim; j++)
            {
                res[lim+j] = res[lim-j-1]+lim;
            }
        }
        
        return res;
    }
};