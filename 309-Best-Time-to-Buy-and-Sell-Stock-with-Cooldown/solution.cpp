class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int buy = 0, sell = 0, emp = 0;
		bool isbuy = false;
		int buypr;
		for (auto pr : prices)
		{
			int tmpsell = sell;
			// for sell
			if (isbuy)
			{
				sell = buy + pr - buypr;
			}

			// for buy
			if (!isbuy || emp - pr > buy - buypr)
			{
				buy = emp;
				buypr = pr;
				isbuy = true;
			}

			// for emp
			emp = max(emp, tmpsell);
		}
		return max(buy, max(emp, sell));
	}
};