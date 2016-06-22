class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char slist[128];
        char tlist[128];
        
        memset(slist, -1, sizeof(slist));
        memset(tlist, -1, sizeof(tlist));
        
        for(int i = 0; i < s.size(); i++)
        {
            if(slist[s[i]] == -1 || tlist[t[i]] == -1)
            {
                if(slist[s[i]] == tlist[t[i]])
                {
                    slist[s[i]] = t[i];
                    tlist[t[i]] = s[i];
                }
                else
                    return false;
            }
            if(slist[s[i]] != t[i] || tlist[t[i]] != s[i])
                return false;
        }
        
        return true;
    }
};