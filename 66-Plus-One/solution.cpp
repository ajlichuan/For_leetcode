class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cnt;
        
        for(cnt = digits.size()-1; cnt >= 0; cnt--)
        {
            if(digits[cnt] == 9)
            {
                digits[cnt] = 0;
            }
            else
            {
                digits[cnt]++;
                return digits;
            }
        }
        
        digits.insert(digits.begin(),1);
        
        return digits;
    }
};