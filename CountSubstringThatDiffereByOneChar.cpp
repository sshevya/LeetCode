/********** 3 solution ************/

class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0)); //all substrings ending at i and j and differ by 0 char
        vector<vector<int>> dp1(n+1,vector<int>(m+1,0));//all substring ending at i and j and differe by 1 char
        int ans =0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    dp1[i][j]=dp1[i-1][j-1];

                }else{
                    dp[i][j]=0;
                    dp1[i][j]=1+dp[i-1][j-1];
                }
                ans+=dp1[i][j];
            }
        }
        return ans;
    }
};

/********** the above sol can be done using 3D dp ************/

/********** another sol on leetcode*************/
