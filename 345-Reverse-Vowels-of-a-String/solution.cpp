class Solution {
public:
    string reverseVowels(string s) {
        int f = 0, l = s.size()-1;
        
        while(f < l)
        {
            while(f < l && s[f] != 'a' && s[f] != 'e' && s[f] != 'i' && s[f] != 'o' && s[f] != 'u' && s[f] != 'A' && s[f] != 'E' && s[f] != 'I' && s[f] != 'O' && s[f] != 'U') f++;
            while(f < l && s[l] != 'a' && s[l] != 'e' && s[l] != 'i' && s[l] != 'o' && s[l] != 'u' && s[l] != 'A' && s[l] != 'E' && s[l] != 'I' && s[l] != 'O' && s[l] != 'U') l--;
            
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