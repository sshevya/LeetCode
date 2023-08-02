class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<int> ans(m,-1);
        if(m==1){
            return ans;
        }
        if(grid[0][0]==1){
            if(grid[0][1]==1)
            dp[0][1]=0;
        }
        
        for(int i=1;i<m;i++){
            if(grid[0][i]==1){
                if(i<m-1 && grid[0][i]==grid[0][i+1]){
                    dp[0][i+1]=i;
                }
            }else{
                if(i>0 && grid[0][i]==grid[0][i-1]){
                    dp[0][i-1]=i;
                }
            }
        }

        for(int i=0;i<m;i++){
            cout<<dp[0][i]<<" ";
        }

        cout<<endl;
         for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                 if(j<m-1 && grid[i][j]==1 && grid[i][j]==grid[i][j+1]){
                        dp[i][j+1] = dp[i-1][j];
                 }
                else if(j<m-1 && grid[i][j]==-1 && grid[i][j]==grid[i][j+1]){
                       dp[i][j]=dp[i-1][j+1];
                }

                if(j<m-1 && grid[i][j]==1 && grid[i][j+1]==-1){  
                    if(j>0 && grid[i][j-1]==-1){
                        dp[i][j]=-1;
                    }else if(j==0){
                        dp[i][j]=-1;
                    }
                    if(j<m-2 && grid[i][j+2]==1){
                        dp[i][j+1]=-1;
                    }else if(j==m-2){
                        dp[i][j+1] =-1;
                    }
                }
                
             }
         }

        for(int i=0;i<m;i++){
            if(dp[n-1][i]>=0)
           ans[dp[n-1][i]] = i;
        }


        return ans;
    }
};
