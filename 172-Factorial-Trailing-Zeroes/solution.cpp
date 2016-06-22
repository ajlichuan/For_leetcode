class Solution {
public:
    int trailingZeroes(int n) {
        if(n <= 4) return 0;
        int zero[(int)log(n)+1];
        
        int cnt = 0;
        int pow = 1;
        int res = 0;
        
        zero[0] = 0;
        
        while(pow <= n/5)
        {
            zero[cnt+1] = zero[cnt] * 5 + 1;
            pow *= 5;
            cnt ++;
        }
        
        while(n > 4)
        {
            int i = 0;
            while(n-pow*(i+1) >= 0) i++;
            
            if(i != 0)
            {
                n = n - pow * i;
                res += i * zero[cnt];
            }
            pow /= 5;
            cnt --;
        }
        
        return res;
    }
};