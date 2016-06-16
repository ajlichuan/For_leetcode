class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1;
        
        for(int i = 1; i <= n; i++)
        {
            int tmp = 9;
            
            for(int j = 1; j < i; j++)
            {
                tmp *= (10-j);
            }
            
            res += tmp;
        }
        
        return res;
    }
};