class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        int len = secret.size();
        
        for(int i=0; i<len; i++)
        {
            if(secret[i] == guess[i])
                A++;
        }
        
        int i=0, j=0;
        
        sort(secret.begin(), secret.end());
        sort(guess.begin(), guess.end());
        while(i < len && j < len)
        {
            if(secret[i] == guess[j])
            {
                B++;
                i++;
                j++;
            }
            else if(secret[i] > guess[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        
        B -= A;
        
        string res;
        if(A < 10)
        {
            res += '0'+A;
        }
        else
        {
            int pow = 1;
            
            while(pow*10 <= A) pow *= 10;
            while(pow!=0)
            {
                res += A/pow+'0';
                A = A%pow;
                pow /= 10;
            }
        }
        res += 'A';
        
        if(B < 10)
        {
            res += '0'+B;
        }
        else
        {
            int pow = 1;
            
            while(pow*10 <= B) pow *= 10;
            while(pow!=0)
            {
                res += B/pow+'0';
                B = B%pow;
                pow /= 10;
            }
        }
        res += 'B';
        
        return res;
    }
};