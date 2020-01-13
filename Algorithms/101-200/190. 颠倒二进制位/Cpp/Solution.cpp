class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        for (int i = 0, j = 32 - 1; i < j; ++ i, -- j) {

            if ((n >> i & 1) == (n >> j & 1))
                continue;

            n ^= 1 << i;
            n ^= 1 << j;
        }
        return n;
    }
};
