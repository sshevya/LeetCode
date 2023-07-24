class Solution {
public:
    // int DFSUtil(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& dungeon){
    //     if(i>=dungeon.size() || j>=dungeon[0].size()){            
    //         return 1e9;
    //     }

    //     if(i==dungeon.size()-1 && j==dungeon[0].size()-1)

    //        return  dungeon[i][j]>0 ? 1: -1*dungeon[i][j]+1;
        
        
    //     cout<<"dp"<<i<<" "<<j<<" "<<dp[i][j]<<endl;


    //      int down = DFSUtil(i+1, j, dp, dungeon);
    //      int left = DFSUtil(i, j+1, dp, dungeon);

    //      int minHealth = min(down, left) - dungeon[i][j];


    //     dp[i][j] =  minHealth<=0?1:minHealth;
    //     return dp[i][j];
    // }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,1e9));
        
        //int ans = DFSUtil(0,0,dp,dungeon);
       dp[n-1][m] = 1;
       dp[n][m-1]=1;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int minHealth = min(dp[i+1][j], dp[i][j+1])-dungeon[i][j];
                dp[i][j] = minHealth<=0 ? 1 : minHealth;
            }
        }


        return dp[0][0];
    }
};
