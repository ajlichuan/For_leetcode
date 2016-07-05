class Solution {
private:
    vector<int> num_set;
    vector<char> opt_set;

    vector<int> res;
    int len;

    int cal(int i, char opt, int j)
    {
        if('*' == opt)
            return i*j;
        if('-' == opt)
            return i-j;
        return i+j;
    }

    void helper(int lastnum, char lastopt, int i, stack<int>& n, stack<char>& opt)
    {
        stack<int> nt(n);
        stack<char> optt(opt);
        int num = num_set[i];
        
        optt.push(lastopt);
        nt.push(lastnum);
        
        if(len-1 == i)
        {
            while(!nt.empty())
            {
                int tmpn = nt.top();
                nt.pop();
                
                char tmpopt = optt.top();
                optt.pop();
                
                num = cal(tmpn,tmpopt,num);
            }
            res.push_back(num);
        }
        else
        {
            helper(num,opt_set[i],i+1,nt,optt);
            
            while(!nt.empty())
            {
                int tmpn = nt.top();
                nt.pop();
                
                char tmpopt = optt.top();
                optt.pop();
                
                num = cal(tmpn,tmpopt,num);
                
                helper(num,opt_set[i],i+1,nt,optt);
            }
        }
        
    }
public:
    vector<int> diffWaysToCompute(string input) {
        len = input.size();
        if(len == 0) return res;
        
        int num = 0;
        for(auto ch : input)
        {
            if(ch == '+' || ch == '-' || ch == '*')
            {
                num_set.push_back(num);
                opt_set.push_back(ch);
                num = 0;
            }
            else
                num = num * 10 + ch - '0';
        }
        num_set.push_back(num);
        
        len = num_set.size();
        if(len == 1) return num_set;
        
        stack<int> n;
        stack<char> opt;
        
        helper(num_set[0], opt_set[0], 1, n, opt);
        
        return res;
    }
};