class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() < 3) return *max_element(nums.begin(), nums.end());
        
        int fr_m_rob = nums[0];
        int fr_m_urob = nums[0];
        int fn_m_rob = nums[1];
        int fn_m_urob = 0;
        
        int i;
        for(i = 2; i < nums.size()-1; i++)
        {
            int tmp = fr_m_urob;
            if(fr_m_urob < fr_m_rob)
                fr_m_urob = fr_m_rob;
            
            fr_m_rob = tmp + nums[i];
            
            tmp = fn_m_urob;
            if(fn_m_urob < fn_m_rob)
                fn_m_urob = fn_m_rob;
            
            fn_m_rob = tmp + nums[i];
        }
        
        return max(max(fr_m_rob, fr_m_urob), max(fn_m_rob, fn_m_urob + nums[i]));
    }
};