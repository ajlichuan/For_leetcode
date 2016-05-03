#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> tmp;
        
        for(auto i:nums)
            if(tmp.find(i) == tmp.end())
                tmp.insert(i);
            else
                return true;
        
        return false;
    }
};