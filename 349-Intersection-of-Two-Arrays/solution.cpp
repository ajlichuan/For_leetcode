class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> tmp;
        vector<int> res;
        
        for(auto num:nums1)
            tmp[num] = 1;
        
        for(auto num:nums2)
        {
            if(tmp[num] == 1)
                res.push_back(num);
            tmp[num] = 0;
        }
                
        return res;
    }
};