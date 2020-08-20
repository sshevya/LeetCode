class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        if(n<2){
            return 0;
        }
        vector<vector<int>> dp(n,(vector<int>(3,0)));
        
        int minv=prices[0];
        
        for(int j=1;j<=2;j++){
            minv=prices[0];
            for(int i=1;i<n;i++){
                dp[i][j]=max(prices[i]-minv,dp[i-1][j]);
                minv=min(minv,prices[i]-dp[i][j-1]);
            }
            
            
            
        }
        
        
        return dp[n-1][2];
        
    }
};
