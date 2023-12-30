/********* Solution 1*********/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right>left){
            right = right & (right-1);
        }

        return left & right;
    }
};

/********** Solution 2 ********/
class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
       int c=0;
       while(l!=r)
       {
           l>>=1;
           r>>=1;
           c++;
       }
       return l<<c;
    }
};
