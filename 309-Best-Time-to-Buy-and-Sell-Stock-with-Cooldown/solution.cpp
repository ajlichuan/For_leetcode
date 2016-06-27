class Solution {
public:
	int maxProfit(vector<int>& prices) {
	    if(prices.size() == 0) return 0;
		int buy = -prices[0], sell = 0, emp = 0;
		for (auto pr : prices)
		{
			int tmpsell = sell;
			// for sell
			sell = buy + pr;

			// for buy
			if(emp - pr > buy)
				buy = emp - pr;
			
			// for emp
			emp = max(emp, tmpsell);
		}
		return max(emp, sell);
	}
};