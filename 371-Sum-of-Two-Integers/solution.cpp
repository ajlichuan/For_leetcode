class Solution {
public:
    int getSum(int a, int b) {
        unsigned int aa = a, bb = b;
        unsigned int pow = 1;
        bool pls = false;
        unsigned int sum = 0;
        
        while(aa != 0 || bb != 0)
        {
            unsigned int ta = aa % 2;
            unsigned int tb = bb % 2;
            
            
            if( pls ? ta == tb : ta != tb )
                sum |= pow;
            pls = pls ? ta == 1 || tb == 1 : ta == 1 && tb == 1;
            
            pow <<= 1;
            aa >>= 1;
            bb >>= 1;
        }
        
        return pls ? (int)(sum | pow) : (int)sum;
    }
};