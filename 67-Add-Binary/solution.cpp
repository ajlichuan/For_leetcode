class Solution {
public:
    void add_to_str(string &a, string &b)
    {
        bool pls = false;
        int i;
        
        for(i = 0; i < b.size(); i++)
        {
            int ia = a.size()-1 - i;
            int ib = b.size()-1 - i;
            /*if(a[ia] == '0')
            {
                if(b[ib] == '0')
                {
                    if(pls)
                    {
                        a[ia] = '1';
                        pls = false;
                    }
                }
                else
                {
                    if(!pls)
                    {
                        a[ia] = '1';
                        pls = false;
                    }
                }
            }
            else
            {
                if(b[ib] == '0')
                {
                    if(pls)
                    {
                        a[ia] = '0';
                    }
                }
                else
                {
                    if(!pls)
                    {
                        a[ia] = '0';
                        pls = true;
                    }
                }
            }*/
            int tmp = a[ia] + b[ib] - '0'*2;
            if(pls) tmp++;
            pls = tmp > 1;
            a[ia] = tmp - ((tmp >> 1) << 1) + '0';
        }
        
        int ia = a.size()-1 - i;
        
        while(pls && ia >= 0)
        {
            if(a[ia] == '0')
            {
                a[ia] = '1';
                pls = false;
            }
            else
            {
                a[ia] = '0';
                ia--;
            }
        }
        
        if(pls)
            a = "1" + a;
    }
    
public:
    string addBinary(string a, string b) {
        if(a.size() > b.size())
        {
            add_to_str(a,b);
            return a;
        }
        else
        {
            add_to_str(b,a);
            return b;
        }
        
        
    }
};