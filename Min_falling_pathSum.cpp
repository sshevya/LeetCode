class Solution {
public:
   // int Y={-1,0,1}
    int minFallingPathSum(vector<vector<int>>& A) {
        
        int n=A.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int mins=INT_MAX;
        //for(int i=0;i<n;i++){
          //  dp[0][i]=A[0][i];
        //}
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int minm=A[i+1][j];
                if(j>0){
                    minm=min(minm,A[i+1][j-1]);
                }
                if(j<n-1){
                    minm=min(minm,A[i+1][j+1]);
                }
               A[i][j]=A[i][j]+minm;//+min(dp[i+1][j],min(dp[i+1][j-1],d[i+1][j+1])) 
                
         

        }         

        }
        
    for(int i=0;i<n;i++){
        mins=min(mins,A[0][i]);
    }
        return mins;
        
    }
};
