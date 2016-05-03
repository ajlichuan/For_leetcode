#include <unordered_map>
class Solution {
public:
    struct node
    {
        int val;
        int cnt;
        friend bool operator< (node a, node b)
        {
            return a.cnt < b.cnt;
        };
    };
        
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<node> que;
        unordered_map<int,int> ele;
        
        for(auto i:nums)
        {
            ele[i] ++;
        }
        
        for(auto i:ele)
        {
            node tmp;
            
            tmp.val = i.first;
            tmp.cnt = i.second;
            que.push(tmp);
        }
        
        vector<int> res;
        
        for(int i = 0; i<k; i++)
        {
            res.push_back(que.top().val);
            que.pop();
        }
        
        return res;
    }
};