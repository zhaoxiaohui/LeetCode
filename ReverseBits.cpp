class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if (n == 0) return 0;
        vector<int> bits(32, 0);
        int id = 0;
        while (n) {
            bits[id++] = n & 1;
            n >>= 1;
        }
        uint32_t ret = 0;
        for (int i = 0; i <= 31; i++) {
            ret <<= 1;
            ret |= bits[i];
        }
        return ret;
    }
};