class Solution {
private:
    int len;
    vector<vector<int>> res;
    unordered_map<int,int> data;
    
    void helper(int cnt, int tres[])
    {
        if(cnt == len-1)
        {
            for(auto it = data.begin(); it != data.end(); ++it)
            {
                if((*it).second > 0)
                {
                    tres[cnt] = (*it).first;
                    res.push_back(vector<int>(tres, tres+len));
                    break;
                }
            }
        }
        else
        {
            for(auto it = data.begin(); it != data.end(); ++it)
            {
                if((*it).second > 0)
                {
                    tres[cnt] = (*it).first;
                    (*it).second--;
                    helper(cnt+1, tres);
                    (*it).second++;
                }
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        len = nums.size();
        int tres[len];
        
        for(auto n : nums)
            data[n]++;
        
        helper(0, tres);
        
        return res;
    }
};