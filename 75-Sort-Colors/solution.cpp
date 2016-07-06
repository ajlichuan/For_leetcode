class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int i,j,tmp,lasti;
        
        for(int c = 0; c < 2; c++)
        {
            i = 0; j = len-1;
            while(i < j)
            {
                while(i < j && nums[i] <= c) i++;
                while(i < j && nums[j] > c) j--;
                tmp = nums[i]; nums[i] = nums[j]; nums[j] = tmp;
                i++; j--;
            }
        }
    }
};