class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m;
        int cnt = 1;
        bool flag = true;
        
        while(res>=cnt)
        {
            if((res&cnt) != 0)
            {
                if(res+cnt > n || res+cnt < 0)
                    break;
                else
                    res &= ~cnt;
            }
            
            cnt <<= 1;
        }
        
        return res;
    }
};