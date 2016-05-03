class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0) return 0;
        
        int res = 1;
        while(n &= n-1) res++;
        
        return res;
    }
};