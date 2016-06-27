class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1=0, p2=0;
        int n1, n2;
        int len1 = version1.size();
        int len2 = version2.size();
        
        while(p1<len1 || p2<len2)
        {
            for(n1=0; p1<len1; p1++)
            {
                char ch = version1[p1];
                if(ch != '.')
                    n1 = n1*10 + ch - '0';
                else
                    break;
            }
            
            for(n2=0; p2<len2; p2++)
            {
                char ch = version2[p2];
                if(ch != '.')
                    n2 = n2*10 + ch - '0';
                else
                    break;
            }
            
            if(n1 != n2)
                return n1>n2 ? 1 : -1;
            
            p1++; p2++;
        }

        return n1 == n2 ? 0 : n1>n2 ? 1 : -1;
    }
};