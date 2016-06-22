class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> pos;
        
        int len = nums.size();
        for(int cnt = 0; cnt < len; cnt++)
        {
            if(pos[nums[cnt]] != 0 && cnt - pos[nums[cnt]] + 1 <= k)
                    return true;

            pos[nums[cnt]] = cnt+1;
        }
        return false;
    }
};