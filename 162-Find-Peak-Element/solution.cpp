class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int p1 = 1, p2 = len-2;
        if(len == 1) return 0;
        if(nums[p1] < nums[0]) return 0;
        if(nums[p2] < nums[len-1]) return len-1;
        
        while(p1 < p2)
        {
            int mid = p1 + (p2-p1)/2;
            
            if(nums[mid-1] < nums[mid])
            {
                p1 = mid;
            }
            else if(nums[mid-1] > nums[mid])
            {
                p2 = mid-1;
                continue;
            }
            
            if(nums[mid] < nums[mid+1])
            {
                p1 = mid+1;
                continue;
            }
            else if(nums[mid] > nums[mid+1])
            {
                p2 = mid;
                continue;
            }
            
            int tp1;
            for(tp1 = mid; tp1 >= p1; tp1--)
            {
                if(nums[tp1]!=nums[tp1-1])
                    break;
            }
            
            if(nums[tp1-1] > nums[tp1])
            {
                p2 = tp1;
                continue;
            }
            
            if(tp1 != p1)
            {
                p1 = tp1;
                continue;
            }
            
            int tp2;
            for(tp2 = mid; tp1 <= p2; tp2++)
            {
                if(nums[tp2]!=nums[tp2+1])
                    break;
            }
            if(nums[tp2] < nums[tp2+1])
            {
                p1 = tp2+1;
                continue;
            }
            if(tp2 != p2)
            {
                p2 = tp2;
            }
            else
            {
                p1 = tp2;
            }
        }
        return p1;
    }
};