class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.size() == 0) return res;
        
        int len = strs.size();
        int cnt = 0;
        
        while(true)
        {
            char ch;
            if(cnt < strs[0].size())
                ch = strs[0][cnt];
            else
                return res;
            
            for(int i = 1; i < len; i++)
            {
                if(cnt >= strs[i].size() || ch != strs[i][cnt])
                    return res;
            }
            
            res += ch;
            cnt++;
        }
        return res;
    }
};