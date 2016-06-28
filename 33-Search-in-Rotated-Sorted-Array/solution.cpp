class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return -1;
        if(target == nums[0]) return 0;
        
        /*int min = nums[0];
        if(target == min) return 0;
        
        
        if(target > min)
        {
            for(int i = 1; i < len; i++)
            {
                if(nums[i] == target) return i;
                if(nums[i] > target || nums[i] < min) return -1;
            }
        }
        else
        {
            int i = 1;
            while(i < len && nums[i] > min) i++;
            while(i < len && nums[i] <= target)
                if(nums[i++] == target)
                    return i-1;
        }
        
        return -1;*/
        
        int p1 = 0, p2 = len-1, mid;
        if(nums[p2] > nums[p1])
            p1 = p2;
        else
        {
            while(p1<p2-1)
            {
                mid = p1 + (p2-p1)/2;
                if(nums[mid] < nums[0])
                {
                    p2 = mid;
                    if(nums[mid-1] > nums[mid])
                    {
                        p1 = mid-1;
                        break;
                    }
                }
                else
                {
                    p1 = mid;
                    if(nums[mid] > nums[mid+1]) break;
                }
            }
        }
        
        if(target > nums[0])
        {
            int t1 = 0, t2 = p1, mid;
            if(nums[t2] < target) return -1;
            if(nums[t2] == target) return t2;
            
            while(t1 < t2-1)
            {
                mid = t1 + (t2-t1)/2;
                
                if(nums[mid] == target) return mid;
                if(nums[mid] > target)
                    t2 = mid;
                else
                    t1 = mid;
            }
            return -1;
        }
        else
        {
            int t1 = p1+1, t2 = len-1, mid;
            if(t1 > t2) return -1;
            if(nums[t1] == target) return t1;
            if(nums[t2] == target) return t2;
            if(nums[t1] > target || nums[t2] < target) return -1;
            
            while(t1 < t2-1)
            {
                mid = t1 + (t2-t1)/2;
                
                if(nums[mid] == target) return mid;
                if(nums[mid] > target)
                    t2 = mid;
                else
                    t1 = mid;
            }
            return -1;
        }
    }
};