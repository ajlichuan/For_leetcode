class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cnt;
        bool plus = true;
        
        for(cnt = digits.size()-1; plus && cnt >= 0; cnt--)
        {
            if(digits[cnt] == 9)
            {
                digits[cnt] = 0;
            }
            else
            {
                digits[cnt]++;
                plus = false;
            }
        }
        
        if(plus)
            digits.insert(digits.begin(),1);
        
        return digits;
    }
};