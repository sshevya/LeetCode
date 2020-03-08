class Solution {
public:
    int min(int a, int b, int c){
       int min=b;
        if(a<b){
             min=a;
        }
        if(c<min){
            return c;
        }else{
            return min;
        }
        
    }
    int minDistance(string word1, string word2) {
        
        int m=word1.length();
        int n=word2.length();
        
        int dp[m+1][n+1]={0};
        
        for(int i=0;i<=m;i++){
            dp[i][0]=i;
        }
            
        for(int i=0;i<=n;i++){
            dp[0][i]=i;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
            }
            }
        }
            
       
        return dp[m][n];
            
    }
};
