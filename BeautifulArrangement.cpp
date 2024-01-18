class Solution {
public:
    void backtrack(vector<int> &v, int n, int curr_num, int &ans){
        if(curr_num>n){
            ans++;
            return;
        }

        for(int i=1; i<=n; i++){
            if(v[i]==0 && (curr_num%i==0 || i%curr_num==0)){
                v[i] = curr_num;
                backtrack(v, n, curr_num+1, ans);
                v[i]=0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> v(n+1,0);
        int ans = 0;

        backtrack(v, n, 1, ans);
        return ans;
    }
};



/********* DP *****/
class Solution {
public:
    int countArrangement(int n) {
        int lim=1<<n;
        vector<int> dp(lim, 0);
        dp[0]=1;
        for(int i=0;i<lim;i++)
        {
            int pos=__builtin_popcount(i);
            for(int j=0;j<n;j++)
            {
             if((i&(1<<j))==0)  
             {
                 int newMask=i|(1<<j);
                 if(((pos+1)%(j+1))==0 || ((j+1)%(pos+1))==0)
                 dp[newMask]=dp[newMask]+dp[i];
             } 
            }
        }
        return dp[(1<<n)-1];
    }
};
