class Solution {
public:
    int countPrimes(int n) {
        if(n < 3) return 0;
        
        bool isPrime[n];
        int cnt;
        
        for(int i = 2; i < n; i++)
            isPrime[i] = true;
            
        for(int i = 2; i*i<n; i++)
        {
            if(!isPrime[i]) continue;
            for(int j = i; j*i<n; j=j+2)
            {
                isPrime[i*j] = false;
            }
        }
        
        cnt = 1;
        for(int i = 3; i < n; i=i+2)
            if(isPrime[i]) cnt++;
        
        return cnt;
    }
};