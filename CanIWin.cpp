class Solution {
public:

    bool recursive_dp(vector<vector<int>> &dp,int mask, int player, int score, int max, int total){
        if(dp[player][mask]!=-1){
            return dp[player][mask];
        }

        for(int i=0;i<max;i++){
            int cmask = 1<<i;
            if((mask & cmask) ==0){
                if((score+i+1>=total) || recursive_dp(dp, (mask | cmask), (player^1), score+i+1, max, total)==false)
                    return dp[player][mask]=1;
            }            
        }

        return dp[player][mask]=0;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal){
            return false;
        }
        vector<vector<int>> dp(2, vector<int>(1<<maxChoosableInteger, -1));
        return recursive_dp(dp, 0, 0, 0, maxChoosableInteger, desiredTotal);
    }
};
