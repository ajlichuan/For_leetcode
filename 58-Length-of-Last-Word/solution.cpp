class Solution {
public:
    int lengthOfLastWord(string s) {
        /*int res = 0;
        int tmp = 0;
        
        for(auto ch : s)
        {
            if(ch == ' ')
            {
                if(tmp != 0)
                    res = tmp;
                tmp = 0;
            }
            else
                tmp++;
        }
        
        if(s[s.size()-1] == ' ')
            return res;
        return tmp;*/
        
        int res = 0;
        
        for(auto it = s.rbegin(); it != s.rend(); ++it)
        {
            if(res == 0 && *it == ' ')
                continue;
            
            if(*it == ' ')
                return res;
            
            res++;
        }
        
        return res;
    }
};