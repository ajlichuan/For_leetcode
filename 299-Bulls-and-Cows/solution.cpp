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
            string tmp;
            
            while(A!=0)
            {
                tmp += '0' + A%10;
                A /= 10;
            }
            
            for(int i=tmp.size()-1; i>=0; i--)
                res+=tmp[i];
        }
        res += 'A';
        
        if(B < 10)
        {
            res += '0'+B;
        }
        else
        {
            string tmp;
            
            while(B!=0)
            {
                tmp += '0' + B%10;
                B /= 10;
            }
            
            for(int i=tmp.size()-1; i>=0; i--)
                res+=tmp[i];
        }
        res += 'B';
        
        return res;
    }
};