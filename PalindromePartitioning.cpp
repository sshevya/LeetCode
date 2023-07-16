class Solution {
public:

    void backtrack(vector<vector<int>>& dp, vector<vector<string>>& ans, vector<string>& temp, string s, int start){
        if(start>=s.length()){
            ans.push_back(temp);
            return;
        }

        
        for(int end=start;end<s.length();end++){
            if(dp[start][end]==1){
                temp.push_back(s.substr(start, end-start+1));
                backtrack(dp,ans,temp,s,end+1);
                temp.pop_back();
            }       
         }



    }


    vector<vector<string>> partition(string s) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n,0));
        vector<vector<string>> ans;

        for(int i =0;i<n-1;i++){
            dp[i][i]=1;
            if(s[i]==s[i+1]){
                dp[i][i+1] = 1;
            }
        }

        dp[n-1][n-1]=1;

        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j = i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                }

            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        vector<string> temp;
        backtrack(dp,ans,temp,s,0);

        
        return ans;
    }
};
