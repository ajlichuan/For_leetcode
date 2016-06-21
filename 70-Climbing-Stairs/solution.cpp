class Solution {
public:
    int loop(int n, int* res)
    {
        if(n <= 2) return n;
        if(res[n] != -1) return res[n];
        
        res[n] = loop(n-1, res) + loop(n-2, res);
        
        return res[n];
    }
    
public:
    int climbStairs(int n) {
        int res[n+1];
        memset(res,-1,sizeof(res));
        
        return loop(n, res);
    }
};