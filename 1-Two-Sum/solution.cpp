class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> n;
        int len = nums.size();
        
        for(int i = 0; i < len; i++)
        {
            int num = nums[i];
            if(n.find(target-num) != n.end())
            {
                vector<int> tmp(2);
                tmp[0] = n[target-num];
                tmp[1] = i;
                return tmp;
            }
            else
            {
                n[num] = i;
            }
        }
        
        return vector<int>();
    }
};