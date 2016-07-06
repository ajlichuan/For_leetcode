class Solution {
public:
    int nthUglyNumber(int n) {
        if(n < 7) return n;
        int pri[3] = {2,3,5};
        int cmp[3] = {8,9,10};
        int pos[3] = {3,2,1};
        int st[n] = {1,2,3,4,5,6};
        int cnt = 6;
        
        while(cnt < n)
        {
            int min = 0;
            for(int i = 1; i < 3; i++)
            {
                if(cmp[min] > cmp[i] && cmp[i] > 0)
                    min = i;
            }
            
            st[cnt++] = cmp[min];
            
            int i = 0;
            while(i != 3)
            {
                cmp[min] = pri[min] * st[++pos[min]];
                
                for(i = 0; i < 3; i++)
                {
                    if(i != min && cmp[min] == cmp[i])
                        break;
                }
            }
        }
        
        return st[n-1];
    }
};