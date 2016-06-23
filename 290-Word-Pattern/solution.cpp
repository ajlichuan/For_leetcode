class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int pmap[26] = {0};
        unordered_map<string, int> smap;
        
        int len1 = pattern.size(), len2 = str.size();
        int p1 = 0, p2 = 0;
        
        while(p1 < len1 && p2 < len2)
        {
            string tmp;
            
            while(str[p2] != ' ' && p2 < len2)
            {
                tmp += str[p2++];
            }
            p2++;
            
            int pcnt = pattern[p1] - 'a';
            if(smap[tmp] == pmap[pcnt])
            {
                p1++;
                smap[tmp]++;
                pmap[pcnt]++;
            }
            else
                return false;
        }
        
        return p1 >= len1 && p2 >= len2;
    }
};