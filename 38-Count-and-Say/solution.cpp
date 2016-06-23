class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        
        for(int i = 1; i<n; i++)
        {
            string st;
            char ch;
            int j,j0;
            int len = res.size();
            
            j = 0;
            
            while(j < len)
            {
                ch = res[j];
                j0 = j;
                while(res[j] == ch && j < len)
                    j++;
                
                st += '0'+j-j0;
                st += ch;
            }
            
            res = st;
        }
        
        return res;
    }
};