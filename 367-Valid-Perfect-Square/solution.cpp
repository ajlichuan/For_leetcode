class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 0 || num > 214739600) return false;
        if(num == 0 || num == 214739600) return true;
        
        int p1 = 0, p2 = 46340;
        int mid, tmp;
        
        while(p2-p1>1)
        {
            mid = p1 + (p2-p1)/2;
            tmp = mid*mid;
            
            if(tmp == num) return true;
            if(tmp > num)
                p2 = mid;
            else
                p1 = mid;
        }
        
        return mid*mid == num;
    }
};