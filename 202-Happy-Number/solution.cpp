class Solution {
public:
    int next(int n)
    {
        int sum = 0;
        
        while(n != 0)
        {
            sum += pow(n % 10,2);
            n = n / 10;
        }
        
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = next(n);
        int cnt = 1;
        int lim = 2;
        
        while(slow != fast)
        {
            if(cnt == lim)
            {
                cnt = 1;
                lim = lim*2;
                slow = fast;
            }
            else
                cnt ++;
        
            fast = next(fast);
        }
        
        return fast == 1 ;
    }
};