class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> n;
        int len = nums.size();
        
        for(int i = 0; i < len; i++)
        {
            if(n[target-nums[i]] != 0)
            {
                vector<int> tmp;
                tmp.push_back(n[target-nums[i]]-1);
                tmp.push_back(i);
                return tmp;
            }
            else
            {
                n[nums[i]] = i+1;
            }
        }
        
        return vector<int>();
    }
};