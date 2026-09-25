class Solution {
public:
    int getSum(int a, int b) {
         //1 + 1,  0001 ^ 0001 -> 0000.
    //Carry if 1 & 1 = 1
    //carry = 0001, shift left -> 0010, calcualte new values
    //0000 (no carry) ^ carry -> 0010
    
    int c = a ^ b; //the sum without carry bits
    int carry = a & b; //There exists a carry bit for every 1 position value.

    while (carry != 0) { //while there are still 1s in the carry variable there are still carry bits
      //Shift carry bits 1 over to the left (so they are in proper position)
      carry <<= 1; 

      a = c; //The old sum (without the carry bit)

      //The carry bit (when xored with the sum, it will carry over resulting in XORing with a 0 or a 1, if there was a 1 in the carry bit position, we need to carry over again)
      b = carry; 


      c = a ^ b;  //store the resulting value back into c
      carry = a & b; //recalculate the carry at the end of each loop (in case we need to carry again).
    }
    return c;
    }
};
