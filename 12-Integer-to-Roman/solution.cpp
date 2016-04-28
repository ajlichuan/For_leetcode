class Solution {
public:
    string intToRoman(int num) {
        string R[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
        };
        
        int n = 0;
        string res = "";
        
        while(num != 0)
        {
            res = R[n++][num%10] + res;
            num = num / 10;
        }
        
        return res;
    }
};