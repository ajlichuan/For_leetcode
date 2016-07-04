class Solution {
public:
    string getPermutation(int n, int k) {
        int p[9] = {1,1,2,6,24,120,720,5040,40320};
        int flag[9] = {0};
        
        int tmp = 0;
        string res;
        k--;
        while(n > 0)
        {
            tmp = k / p[n-1];
            k -= tmp * p[n-1];
            n--;
            for(int i = 0; ; i++)
            {
                if(flag[i] == 0)
                {
                    tmp--;
                    if(tmp < 0)
                    {
                        flag[i] = 1;
                        res.push_back(i+'1');
                        break;
                    }
                }
            }
        }
        
        return res;
    }
};