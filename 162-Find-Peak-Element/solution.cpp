class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int p1 = 0, p2 = len-1;
        while(p1<p2)
        {
            int mid = p1 + (p2-p1)/2;
            if(nums[mid] < nums[mid+1])
                p1 = mid+1;
            else
                p2 = mid;
        }
        
        return p1;
    }
};