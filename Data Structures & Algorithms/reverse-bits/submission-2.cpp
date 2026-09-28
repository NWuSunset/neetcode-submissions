class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //reversing bit via divide and conquer
        //First two halves, then  bytes, etc.

        uint32_t res = n; //to modify

        //first flip the two halves
        res = (res >> 16) | (res << 16); //rightshift OR leftshift flips

        //now do for the smaller values in the two flipped halves (flip bytes in the two halves)

        //Copy over the odd and even blocks and shift them 
        //res & 11111111000000001111111100000000 -> 00000000111111110000000011111111 (copied data at the 1s) | res & 00000000111111110000000011111111 (copied data at the 1s) ->lshift 11111111000000001111111100000000 (copy over values which is the same as flipping the adjacnet bytes)
        res = ((res & 0xff00ff00) >> 8) | ((res & 0x00ff00ff) << 8);
        res = ((res & 0xf0f0f0f0) >> 4) | ((res & 0x0f0f0f0f) << 4);
        res = ((res & 0xcccccccc) >> 2) | ((res & 0x33333333) << 2);
        res = ((res & 0xaaaaaaaa) >> 1) | ((res & 0x55555555) << 1);
        return res;
    }
};
