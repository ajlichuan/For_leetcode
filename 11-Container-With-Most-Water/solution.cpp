class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int left = -1;
        int right = height.size();
       
        while(height[++left] == 0);
        while(height[--right] == 0);
       
        while(left != right)
        {
            if(height[left] < height[right])
            {
                if(maxA < (right - left) * height[left]) maxA = (right - left) * height[left];
                int tmp = height[left];
                while(height[++left] <= tmp && right > left);
            }
            else
            {
                if(maxA < (right - left) * height[right]) maxA = (right - left) * height[right];
                int tmp = height[right];
                while(height[--right] <= tmp && right > left);
            }
       }
       return maxA;
    }
};