class Solution {
public:

    long long rec(long long n){
        if(n==1){
            return 0;
        }
        if(n%2==0){
            return rec(n>>1)+1;
        }
        return min(rec(n+1)+1, rec(n-1)+1);
    }

    int integerReplacement(int n) {
       return rec(n);
    }
};
