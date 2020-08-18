class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        int X[]={1,-1,1,-1,2,-2,2,-2};
        int Y[]={2,2,-2,-2,1,1,-1,-1};
        
      //  vector<vector<vector<double>>> dp(N,vector<vector<double>>(N,vector<double>(K+1,0)));
        vector<vector<double>> dp(N,vector<double>(N,0));
        vector<vector<double>> dp2(N,vector<double>(N,0));
       /* for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dp2[i][j]=1;
            }
        }*/
        dp[r][c]=1;
        
        for(;K>0;K--){
            vector<vector<double>> dp2(N,vector<double>(N,0));

            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    double p=0;
                    
                    for(int s=0;s<8;s++){
                    int x=i+X[s];
                        int y=j+Y[s];
                        if(x>=0 && y>=0 && x<N && y<N){
                            dp2[x][y]+=dp[i][j]*double(1)/double(8);
                        }
                    }
                    
                }
            }
                                    dp=dp2;

        }
        
        
        
          double ans = 0.0;
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) ans += dp[i][j];
        }
        
        return ans;
        
        
        
    }
};
