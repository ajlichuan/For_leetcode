class Solution {
public:
    int n2ch[9] = {0,3,6,9,12,15,19,22,26};
public:
    void loop(string &digits, string s, int cnt, vector<string> &res)
    {
        if(cnt >= digits.size())
        {
            res.push_back(s);
        }
        else
        {
            char ch = digits[cnt];
            if(ch >= '2' && ch <= '9')
            {
                for(char tch = 'a'+n2ch[ch-'2']; tch < 'a'+n2ch[ch-'2'+1]; tch ++)
                {
                    loop(digits, s+tch, cnt+1, res);
                }
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        
        if(digits.size() == 0) return res;

        loop(digits, "", 0, res);
        
        return res;
    }
};