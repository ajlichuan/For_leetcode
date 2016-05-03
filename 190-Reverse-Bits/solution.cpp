class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bit(n), res;
        
    	for (int i = 0; i < 32; i++)
    	{
    		res[i] = bit[31-i];
    	}
    
        return res.to_ulong();
    }
};