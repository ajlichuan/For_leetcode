class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int len = citations.size();
        
        int i;
        for(i = len-1; i >= 0 ; i--)
            if(citations[i] < len-i)
                break;
        
        return len-1-i;
    }
};