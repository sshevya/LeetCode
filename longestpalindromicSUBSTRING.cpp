class Solution {
public:
    
    string longestPalindrome(string s) {
        
        int n=s.length();
        if(n==0){
            return "";
        }
        int dp[n][n]={0};
        int start=0,maxlen=1;
        for(int i=0;i<n-1;++i){
            dp[i][i]=1;
    
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                start=i;
                maxlen=2;
            }
        }
        dp[n-1][n-1]=1;
        int j;
        
        for(int k=3;k<=n;++k){
            for(int i=0;i<n-k+1;++i){
              j=i+k-1;
                
                if(dp[i+1][j-1]==1 && s[i]==s[j]){
                    dp[i][j]=1;
                    if(k>maxlen){
                    start=i;
                    maxlen=k;
                    }
                }
                
                
            }
        }
        
        string a="";
        for(int i=start;i<start+maxlen;++i){
            a+=s[i];
        }
        
        
        
        
        
        
        
     return a;
    }
};
