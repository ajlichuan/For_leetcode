class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> n1;
        vector<int> res;
        
        for(auto num:nums1)
            n1[num]++;
            
        for(auto num:nums2)
        {
            if(n1[num] > 0)
                res.push_back(num);
            
            n1[num]--;
        }
        
        return res;
    }
};