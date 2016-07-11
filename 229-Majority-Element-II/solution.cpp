class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        if(len<2) return nums;
        
        int x1 = 0, cnt1 = 0;
        int x2 = 1, cnt2 = 0;
        
        for(auto n : nums)
        {
            if(n == x1)
            {
                cnt1++;
            }
            else if(n == x2)
            {
                cnt2++;
            }
            else if(cnt1 == 0)
            {
                x1 = n;
                cnt1 = 1;
            }
            else if(cnt2 == 0)
            {
                x2 = n;
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0; cnt2 = 0;
        for(auto n : nums)
        {
            if(n == x1) cnt1++;
            if(n == x2) cnt2++;
        }
        
        vector<int> res;
        if(cnt1 > len/3) res.push_back(x1);
        if(cnt2 > len/3) res.push_back(x2);
        
        return res;
    }
};