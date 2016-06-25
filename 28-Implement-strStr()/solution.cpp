class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        if(needle.size() > haystack.size()) return -1;
        
        int p = 0;
        int len = haystack.size()-needle.size();
        int lenn = needle.size();
        
        while(p <= len)
        {
            if(haystack[p] == needle[0])
            {
                int tmp;
                for(tmp = 1; tmp < lenn; tmp++)
                    if(haystack[p+tmp] != needle[tmp])
                        break;
                if(tmp == lenn)
                    return p;
            }
            p++;
        }
        
        return -1;
    }
};