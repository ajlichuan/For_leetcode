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
        
        string res = to_string(A) + 'A' + to_string(B) + 'B';

        return res;
    }
};