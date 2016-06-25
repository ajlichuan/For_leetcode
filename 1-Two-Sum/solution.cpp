class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> n;
        int len = nums.size();
        
        for(int i = 0; i < len; i++)
        {
            if(n.find(target-nums[i]) != n.end())
            {
                vector<int> tmp(2);
                tmp[0] = n[target-nums[i]];
                tmp[1] = i;
                return tmp;
            }
            else
            {
                n[nums[i]] = i;
            }
        }
        
        return vector<int>();
    }
};