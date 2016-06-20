class Solution {
public:
    int numTrees(int n) {
        vector<int> nums(n+1,1);
        
        for(int i=2; i<=n; i++)
        {
            nums[i] = 0;
            for(int j=0; j<i/2; j++)
            {
                nums[i] = nums[i] + nums[j] * nums[i-j-1];
            }
            nums[i] = nums[i] * 2;
            
            if((i - ((i >> 1) << 1)) != 0)
                nums[i] = nums[i] + nums[i/2] * nums[i/2];
        }
        
        return nums[n];
    }
};