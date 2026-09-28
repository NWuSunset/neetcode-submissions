class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //The reversed bit will always be stored at index 31 - i
        uint32_t res = 0; //reversed number

        for (int i = 0; i < 32; i++) {
            //get the ith bit
            uint32_t bit = (n >> i) & 1;
            //Shift bit to posititon and add to res (adding will basically do the same at setting the bit at res. with a bitwise OR)
            res += bit << (31 - i);
        }
        return res;
    }
};
