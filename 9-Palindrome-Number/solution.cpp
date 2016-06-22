class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x < 0 || x%10 == 0) return false;
        
        int rev = 0;
        
        while(x>rev)
        {
            rev = rev*10 + x%10;
            x /= 10;
        }
        
        return rev == x || rev/10 == x;
        /*int pown = 1;
        
        while(x/10 >= pown) pown *= 10;
        
        while(pown >= 10)
        {
            if(x/pown != x-x/10*10)
                return false;
            pown /= 10;
            x /= 10;
            x -= x/pown*pown;
            pown /= 10;
        }*/
        
        /*int num[10];
        int cnt = 0;
        
        while(x != 0)
        {
            num[cnt++] = x%10;
            x /= 10;
        }
        
        for(int i = 0; i<cnt/2; i++)
            if(num[i] != num[cnt-1-i])
                return false;
        
        return true;*/
    }
};