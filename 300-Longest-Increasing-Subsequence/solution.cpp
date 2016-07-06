class Solution {
private:
    int find(int e, int tar, int lis[])
    {
        if(lis[e] < tar)
            return e+1;
        int mid, s = 0;
        while(s<e)
        {
            mid = s + (e-s)/2;
            if(lis[mid] < tar)
                s = mid+1;
            else
                e = mid;
        }
        return s;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int max = 0;
        int len = nums.size();
        if(len < 2) return len;
        
        int lis[len];
        
        lis[0] = nums[0];
        
        for(int i = 1; i < len; i++)
        {
            int pos = find(max,nums[i],lis);
            lis[pos] = nums[i];
            if(pos > max) max=pos;
        }
        
        return max+1;
    }
};