class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);

        if(n==0){
            return dp;
        }
        dp[0]=0;
        dp[1]=1;
        //dp[2]=1;
        int pow2 = 2;

        for(int i=2;i<=n;i++){
            //cout<<i<<" "ceil(log2())<<" "<<floor(log2(n))<<endl;
            if(ceil(log2(i))==floor(log2(i))){
                cout<<i<<" ";
                pow2=i;
                dp[i]=1;
            }else{
                dp[i]=dp[i-pow2]+1;
            }
        }

        return dp;
    }
};
