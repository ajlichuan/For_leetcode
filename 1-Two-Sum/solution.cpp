class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int cnt = -1;
        
        for(vector<int>::iterator n = nums.begin(); n != nums.end(); ++n)
        {
            cnt++;
            auto s = find(n+1,nums.end(),target-*n);
            if(s != nums.end()) break;
        }
        
        vector<int> res(2,cnt);
        int two = target - nums[cnt];
        
        for(int i = cnt+1; ;i++)
        {
            if(nums[i] == two)
            {
                res[1] = i;
                return res;
            }
        }
        
        
        /*unordered_map<int,int> n;
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
        }*/
        
        return vector<int>();
    }
};