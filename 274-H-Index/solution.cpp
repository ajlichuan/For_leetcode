class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int len = citations.size();
        if(len == 0 || citations[len-1] == 0) return 0;
        
        int p1 = 0, p2 = len-1;
        while(p1 < p2)
        {
            int mid = p1 + (p2-p1)/2;
            if(citations[mid] < len-mid)
                p1 = mid+1;
            else
                p2 = mid;
        }
        
        return len-p1;
    }
};