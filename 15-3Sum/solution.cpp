class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        if(len < 3) return res;
        
        vector<int> row(3);
        
        sort(nums.begin(),nums.end());
        long sum;
        
        long mini = 0-nums[len-1]-nums[len-2];
        for(int i = 0; i < len-2; i++)
        {
            if(nums[i] < mini || (i>0 && nums[i] == nums[i-1])) continue;
            if(nums[i] > 0) break;
            
            row[0] = nums[i];
            sum = -nums[i];
            
            int j = i+1, k = len-1;
            while(j < k)
            {
                while(j<k && (nums[j]+nums[k] < sum || (j>i+1 && nums[j] == nums[j-1]))) j++;
                while(j<k && (nums[j]+nums[k] > sum || (k<len-1 && nums[k] == nums[k+1]))) k--;
                
                if(j<k && nums[j]+nums[k] == sum)
                {
                    row[1] = nums[j];
                    row[2] = nums[k];
                    res.push_back(row);
                }
                
                j++;
            }
        }
        
        return res;
    }
};