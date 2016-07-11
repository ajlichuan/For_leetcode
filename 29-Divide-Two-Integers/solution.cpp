class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 0) return INT_MAX;
        
        bool pos = true;
        
        if(divisor > 0)
        {
            pos = !pos;
            divisor = -divisor;
        }
        
        if(dividend > 0)
        {
            pos = !pos;
            dividend = -dividend;
        }

        if(divisor < dividend) return 0;
        if(divisor == dividend) return pos? 1: -1;
        
        dividend = -(dividend-divisor);
        divisor = -divisor;
        
        if(divisor == 1) return pos ? dividend == INT_MAX ? INT_MAX : dividend+1 : -dividend-1;
        //if(divisor == 2) return pos ? (dividend >> 1)+1 : -(dividend >> 1)-1 ;
        
        int res = 0;
        int tmp = divisor;
        int tres = 1;
        
        while(dividend >= 0)
        {
            res += tres;
            
            if(dividend > tmp)
            {
                if(dividend - tmp - tmp >= 0)
                {
                    tmp = tmp + tmp;
                    tres = tres+tres;
                }
            }
            else
            {
                tmp = divisor;
                tres = 1;
            }
                
            dividend = dividend - tmp;
        }
            
        return pos ? res : -res;
    }
};