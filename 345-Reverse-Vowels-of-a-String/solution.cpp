class Solution {
public:
    string reverseVowels(string s) {
        int f = 0, l = s.size()-1;
        
        while(f < l)
        {
            while(true)
            {  
                char tch;
                if(s[f] < 'a')
                    tch = s[f] - 'A' + 'a';
                else
                    tch = s[f];
                
                if(f < l && tch != 'a' && tch != 'e' && tch != 'i' && tch != 'o' && tch != 'u')
                    f++;
                else
                    break;
            }
            while(true)
            {
                char tch;
                if(s[l] < 'a')
                    tch = s[l] - 'A' + 'a';
                else
                    tch = s[l];
                
                if(f < l && tch != 'a' && tch != 'e' && tch != 'i' && tch != 'o' && tch != 'u')
                    l--;
                else
                    break;
            }
            
            if(f < l)
            {
                char tmp = s[f];
                s[f] = s[l];
                s[l] = tmp;
                f++;
                l--;
            }
        }
        
        return s;
    }
};