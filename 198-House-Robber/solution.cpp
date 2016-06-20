class Solution {
public:
    int rob(vector<int>& nums) {
        int m_rob = 0;
        int m_urob = 0;
        
        for(auto m:nums)
        {
            int tmp = m_urob;
            m_urob = max(m_urob, m_rob);
            m_rob = tmp + m;
        }
        
        return max(m_urob, m_rob);
    }
};