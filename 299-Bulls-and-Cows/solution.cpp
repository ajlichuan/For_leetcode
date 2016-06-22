class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        int len = secret.size();
        int sec[10]={0}, gue[10]={0};
        
        for(int i=0; i<len; i++)
        {
            if(secret[i] == guess[i])
                A++;
            sec[secret[i]-'0']++;
            gue[guess[i]-'0']++;
        }
        
        for(int i = 0; i < 10; i++)
        {
            B += min(sec[i],gue[i]);
        }
        
        string res = to_string(A) + 'A' + to_string(B-A) + 'B';

        return res;
    }
};