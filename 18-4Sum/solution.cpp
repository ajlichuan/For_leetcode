class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        
        int len = nums.size();
        if(len < 4) return res;
        
        vector<int> row(4);
        
        sort(nums.begin(), nums.end());
        long sum = target;
        long mini = nums[len-1] + nums[len-2] + nums[len-3];
        long minj = nums[len-1] + nums[len-2];
        long mink = nums[len-1];
        
        for(int i = 0; i < len-3; i++)
        {
            if(nums[i] > sum/4) break;
            if((i != 0 && nums[i] == nums[i-1]) || nums[i] < sum-mini) continue;
            
            sum -= nums[i];
            row[0] = nums[i];
            
            for(int j = i+1; j < len-2; j++)
            {
                if(nums[j] > sum/3) break;
                if((j != i+1 && nums[j] == nums[j-1]) || nums[j] < sum-minj) continue;
                
                sum -= nums[j];
                row[1] = nums[j];
                
                for(int k = j+1; k < len-1; k++)
                {
                    if(nums[k] > sum/2) break;
                    if((k != j+1 && nums[k] == nums[k-1]) || nums[k] < sum-mink) continue;
                    
                    sum -= nums[k];
                    row[2] = nums[k];
                    
                    for(int l = k+1; l < len; l++)
                    {
                        if(nums[l] == sum)
                        {
                            row[3] = nums[l];
                            res.push_back(row);
                            break;
                        }
                        if(nums[l] > sum)
                            break;
                    }
                    
                    sum += nums[k];
                }
                
                sum += nums[j];
            }
            
            sum += nums[i];
        }
        
        return res;
    }
};