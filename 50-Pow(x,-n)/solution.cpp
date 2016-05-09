class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1)
            return 1;
        if(x == -1)
            if(n % 2 == 0)
                return 1;
            else
                return -1;
        
        if(n > 0)
        {
            n = -n;
            x = 1/x;
        }
        double res = x;
        
        while(++n && res < 1 / 0.0000001) res *= x;
        return 1/res;
    }
};