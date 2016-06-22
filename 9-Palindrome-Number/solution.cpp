class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        
        int pown = 1;
        
        while(x/10 >= pown) pown *= 10;
        
        while(pown >= 10)
        {
            if(x/pown != x-x/10*10)
                return false;
            pown /= 10;
            x /= 10;
            x -= x/pown*pown;
            pown /= 10;
        }
        
        return true;
    }
};