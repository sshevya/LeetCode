class Solution {
public:


    int hammingWeight(uint32_t n) {
       const vector<int> count4_bits = {
           0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4
       };
       
       int count = 0 ;
       for(int i=0;i<8;i++){
           count += count4_bits[n&0b1111];
            n = n>>4;
       }
       return count;
    }
};
