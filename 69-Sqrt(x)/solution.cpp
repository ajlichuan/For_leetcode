class Solution {
public:
	int mySqrt(int x) {
		if (x < 2) return x;

		int left = 1, right = x;
		int mid = left/2.0 + right/2.0;
		
		while(mid > left)
		{
		    if(mid == x / mid) return mid;
		    
		    if(mid > x / mid)
		        right = mid;
		    else
		        left = mid;
		        
		    mid = left/2.0 + right/2.0;
		}
		
		return mid;
	}
};