class Solution {
public:
    int integerBreak(int n) {
        if(n < 4)
            return n - 1;
        else
            return n%3 == 0 ? pow(3,n/3) : pow(3,n/3-1) * (2+2*(n%3));
    }
};