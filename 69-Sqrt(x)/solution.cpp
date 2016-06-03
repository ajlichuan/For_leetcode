class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        
        int pow = 1;
        
        while(pow*pow <= x/100) pow *= 10;
        
        int res = 0;

        do
        {
            int tmp = 0, tmpx = (x - res * res)/pow;
            
            while(tmp < 10 && tmp * tmp * pow + 2 * res * tmp  <= tmpx) tmp++;
            
            res += pow * (tmp-1);
            
            pow /= 10;
            
        }while(pow != 0);
        
        return res;
    }
};