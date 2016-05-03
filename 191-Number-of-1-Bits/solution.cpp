class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        
        while(n != 0)
        {
            n &= n-1;  // 每次去掉一个1
            res++;
        }
        
        return res;
    }
};