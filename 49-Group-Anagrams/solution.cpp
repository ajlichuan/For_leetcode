class Solution {
    vector<vector<string>> res;
    unordered_map<string,int> map;
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        int pos = -1;
        for(int i = 0; i < len; i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            
            int pt = 0;
            if(map.find(tmp) == map.end())
            {
                pt = ++pos;
                res.push_back(vector<string>());
                map[tmp] = pt;
            }
            else
                pt = map[tmp];
                
            res[pt].push_back(strs[i]);
        }
        return res;
    }
};