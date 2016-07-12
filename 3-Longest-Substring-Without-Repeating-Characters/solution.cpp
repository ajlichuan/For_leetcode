class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int charr[128] = {0};
        int res = 0;
        
        int st = 0, now = 0;
        
        for(auto ch : s)
        {
            while(charr[ch] != 0)
            {
                charr[s[st++]] = 0;
            }
            
            charr[ch]++;
            now++;
            
            res = max(res,now - st);
        }
        
        return res;
    }
};