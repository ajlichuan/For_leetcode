class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int len = s.size();
        int dj = numRows == 1 ? 1 : 2*numRows-2;
        for(int i = 0; i < numRows; i++)
        {
            if(i==0||i==numRows-1)
            {
                for(int j=0; i+j<len; j=j+dj)
                    res+=s[i+j];
            }
            else
            {
                for(int j=0; i+j<len; j=j+dj)
                {
                    res+=s[i+j];
                    if(j+dj-i >= len) break;
                    res+=s[j+dj-i];
                }
            }
        }
        
        return res;
    }
};