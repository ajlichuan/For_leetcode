class Solution {
public:
    int myAtoi(string str) {
        
        long res = 0;
        bool pos = true;
        int i = -1;

        while(str[++i] == ' ');
        
        if(str[i] == '+')
        {
            i++;
        }
        else if(str[i] == '-')
        {
            i++;
            pos = false;
        }
        
        for(; i < str.size(); i++)
        {
            int tmp = str[i] - '0';
            if(tmp >= 0 && tmp <= 9)
                res = res * 10 + tmp;
            else
                break;
                
            if(res > INT_MAX || (!pos && -res < -INT_MIN))
                return pos ? INT_MAX : INT_MIN;
        }
        
        return pos ? res : -res;
    }
};