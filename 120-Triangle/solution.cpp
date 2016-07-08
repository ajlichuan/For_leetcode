class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size();
        
        for(int lay = h-2; lay >=0; lay--)
        {
            for(int cnt = 0; cnt <= lay; cnt++)
            {
                triangle[lay][cnt] += min(triangle[lay+1][cnt],triangle[lay+1][cnt+1]);
            }
        }
        
        return triangle[0][0];
    }
};