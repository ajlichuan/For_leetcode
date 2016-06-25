class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        
        int lenh = haystack.size();
        int lenn = needle.size();
        
        for(int i=0; i<lenh-lenn+1; i++)
        {
            int j;
            for(j = 0; j<lenn; j++)
            {
                if(haystack[i+j] != needle[j]) break;
            }
            if(j == lenn) return i;
        }
        
        return -1;
    }
};