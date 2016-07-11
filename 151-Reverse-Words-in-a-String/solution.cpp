class Solution {
public:
    void reverseWords(string &s) {
        
        auto it = s.begin();
        while(*it == ' ')
        {
            it = s.erase(it);
        }
        
        reverse(s.begin(),s.end());
        
        it = s.begin();
        while(*it == ' ')
        {
            it = s.erase(it);
        }
        
        while(it != s.end())
        {
            auto last = it;
            
            while(it != s.end() && *it != ' ') ++it;
            
            reverse(last, it);
            
            if(it == s.end())
                return;
            else
                ++it;
            
            while(it != s.end() && *it == ' ')
            {
                it = s.erase(it);
            }
        }
        
        return;
    }
};