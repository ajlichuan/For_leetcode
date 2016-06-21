class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        //return (n > 0) && (1162261467 / n == 1162261467.0 / n);
        while(n / 3.0 == n / 3)
            n = n / 3;
        
        return n == 1;
    }
};