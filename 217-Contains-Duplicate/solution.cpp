#include <unordered_map>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int,bool> tmp;
        
        for(auto i:nums)
            if(!tmp[i])
                tmp[i] = true;
            else
                return true;
        
        return false;
    }
};