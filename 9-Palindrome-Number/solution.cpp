class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        
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
        
        int num[10];
        int cnt = 0;
        
        while(x != 0)
        {
            int tmp = x/10;
            num[cnt++] = x-tmp*10;
            x = tmp;
        }
        
        for(int i = 0; i<cnt/2; i++)
            if(num[i] != num[cnt-1-i])
                return false;
        
        return true;
    }
};