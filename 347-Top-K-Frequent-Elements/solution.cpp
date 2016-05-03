#include <unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue< pair<int,int> > que;
        unordered_map<int,int> ele;
        
        for(auto i:nums)
        {
            ele[i] ++;
        }
        
        for(auto i:ele)
        {
            que.push(make_pair(i.second,i.first));
        }
        
        vector<int> res;
        
        for(int i = 0; i<k; i++)
        {
            res.push_back(que.top().second);
            que.pop();
        }
        
        return res;
    }
};