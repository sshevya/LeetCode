class Solution {
public:
    int numDecodings(string s) {
         int n=s.length();
        if(n==0){
            return 0;
        }else if(n==1){
           
            if(s[0]=='0'){
            return 0;
            }else{
                return 1;
            }
        }
        if(s[0]=='0'){
            return 0;
        }
        int dp[n+1]={0};
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            dp[i]=0;
            if(s[i-1]>'0'){
                dp[i]=dp[i-1];
            }
           if(s[i-2]=='1' || s[i-2]=='2' && s[i-1]< '7'){
               dp[i]+=dp[i-2];
           }
            
            
            
            
        }      
        
        return dp[n];
    }
};
