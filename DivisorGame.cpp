class Solution {
public:

    bool rec(int n, bool isAlice, vector<int>& dp){
        if(n==1){
            return !isAlice;
        }
        bool ans=false;
        if(dp[n]!=-1){
            return dp[n];
        }
        for(int x=1;x<n;x++){
            if(n%x==0){
                ans = ans || rec(n-x, !isAlice, dp);
            }
        }
        dp[n]=ans;
        return ans;

    }
    bool divisorGame(int n) {
        vector<int> dp(n+1, -1);
        return rec(n, true, dp);
    }
};
