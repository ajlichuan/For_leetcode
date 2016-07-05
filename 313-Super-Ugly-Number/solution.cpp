class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int plen = primes.size();
        vector<int> cmp(primes);
        vector<int> pos(plen,0);
        vector<int> st{1};
        n--;
        
        while(n>0)
        {
            int tmp = 0;
            for(int i = 1; i < plen; i++)
            {
                if(cmp[tmp] > cmp[i])
                    tmp = i;
            }
            st.push_back(cmp[tmp]);
            n--;
            
            int i=0;
			while (i != plen)
			{
				cmp[tmp] = primes[tmp] * (st[++pos[tmp]]);
				for (i = 0; i < plen; i++)
				{
					if (cmp[i] == cmp[tmp] && i != tmp)
						break;
				}
			}
        }
        
        return st.back();
    }
};