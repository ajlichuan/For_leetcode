class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        
        int maxp = 0;
        int state = 0;
        int low = prices[0];
        int high = prices[0];
        
        for(auto p : prices)
        {
            if(p < low)
            {
                maxp = max(maxp, high - low);
                low = p;
                high = p;
            }
            else
            {
                if(p > high)
                    high = p;
            }
        }
        
        return max(maxp, high - low);
    }
};