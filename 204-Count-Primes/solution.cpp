class Solution {
public:
    int countPrimes(int n) {
        bool isPrime[n];
        int cnt;
        
        for(int i = 2; i < n; i++)
            isPrime[i] = true;
            
        for(int i = 2; i*i<n; i++)
        {
            if(!isPrime[i]) continue;
            for(int j = i; j*i<n; j++)
            {
                isPrime[i*j] = false;
            }
        }
        
        cnt = 0;
        for(int i = 2; i < n; i++)
            if(isPrime[i]) cnt++;
        
        return cnt;
    }
};