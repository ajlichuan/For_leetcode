class Solution {
public:
    vector<string> res;
    int cnt_l, cnt_r, all;
    
public:
    void loop(string &rs, int cnt)
    {
        if(cnt >= all)
        {
            res.push_back(rs);
        }
        else
        {
            if(cnt_l != 0)
            {
                rs[cnt] = '(';
                cnt_l --;  cnt_r ++;
                loop(rs, cnt+1);
                cnt_l ++;  cnt_r --;
            }
            
            if(cnt_r != 0)
            {
                rs[cnt] = ')';
                cnt_r --;
                loop(rs, cnt+1);
                cnt_r ++;
            }
        }

    }
    
public:
    vector<string> generateParenthesis(int n) {
        string rs(2*n,'(');
        cnt_l = n;
        cnt_r = 0;
        all = 2*n;
        
        loop(rs, 0);
        
        return res;
    }
};