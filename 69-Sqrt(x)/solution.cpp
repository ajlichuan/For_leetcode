class Solution {
public:
	int mySqrt(int x) {
		if (x < 2) return x;

		int dp = 4;
		int pow = 0;

		while (1 << (pow * 2) <= x >> (2 * dp)) pow = pow + dp;

		int res = 0;

		do
		{
			int tmp = 0, tmpx = (x - res * res) >> pow;

			while (tmp < (1 << dp) && ((tmp * tmp) << pow) + 2 * res * tmp <= tmpx) tmp++;

			res += (tmp - 1) << pow;

			pow -= 4;

		} while (pow >= 0);

		return res;
	}
};