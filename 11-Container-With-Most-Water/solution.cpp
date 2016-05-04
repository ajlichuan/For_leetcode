class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<pair<int,int>> h(height.size());
        
        for(int i = 0; i < height.size(); i++)
        {
            h[i].first = height[i];
            h[i].second = i;
        }
        
        sort(h.begin(),h.end());
        
        int n = h.size()-1;
        int maxi = h[n].second;
        int mini = h[n].second;
        int maxA = 0;
        
        for(n--; n >= 0; n--)
        {
            if(h[n].first == 0) break;
            
            int tmpi = h[n].second;
            if(tmpi > maxi)
            {
                maxi = tmpi;
                if((tmpi - mini) * h[n].first > maxA)
                    maxA = (tmpi - mini) * h[n].first;
                    
                continue;
            }
            
            if(tmpi < mini)
            {
                mini = tmpi;
                if((maxi - tmpi) * h[n].first > maxA)
                    maxA = (maxi - tmpi) * h[n].first;
                    
                continue;
            }
            
            int di = max(tmpi - mini, maxi - tmpi);
            
            if(di * h[n].first > maxA)
                maxA = di * h[n].first;
        }
        
        return maxA;
    }
};