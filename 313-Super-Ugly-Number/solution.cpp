class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int plen = primes.size();
        int cmp[plen];
        int pos[plen];
        vector<int> st{1};
        n--;
        
        memset(pos, 0, sizeof(pos));
        for(int i = 0; i < plen; i++)
            cmp[i] = primes[i];
        
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