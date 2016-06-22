class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size()-1;
        
        while(j >= 0 && nums[j] == val) j--;
        
        while(i < j)
        {
            if(nums[i] == val)
            {
                nums[i] = nums[j--];
                while(j > i && nums[j] == val) j--;
            }
            i++;
        }
        
        return j+1;
    }
};