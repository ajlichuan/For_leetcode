class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int len = heights.size();
        stack<int> high;
        int res = 0;
        
        for(int i = 0; i < len; i++)
        {
            while(high.size() > 0 && heights[i] <= heights[high.top()])
            {
                int h = heights[high.top()];
                high.pop();
                
                int tlen = (high.size() == 0 ? i : i - high.top()-1);
                res = max(tlen*h,res);
            }
            high.push(i);
        }
        
        return res;
    }
};