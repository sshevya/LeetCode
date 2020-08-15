class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n=s.length();
        int m=p.length();
        
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        
        dp[0][0]=1;
        
        for(int i=2;i<m+1;i++){
            if(p[i-1]=='*'){
                dp[0][i]=dp[0][i-2];
            }
        }
        
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==p[j-1] ||p[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }else if(p[j-1]=='*'){
                    dp[i][j]=dp[i][j-2];
                    
                    
                    if(p[j-2]==s[i-1] || p[j-2]=='.'){
                        dp[i][j]=dp[i][j] | dp[i-1][j];
                    }
                    
                    
                }
            }
        }
        
        return dp[n][m];
        
    }
};
