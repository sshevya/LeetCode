/********* 1D DP **********************/

class Solution {
public:

    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefixSum(n+1,0);
        vector<double> dp(n,0);

       // prefixSum[0] = nums[0];
        
        for(int i=0;i<n;i++){
            prefixSum[i+1] = prefixSum[i] + nums[i];
            
        }

       // dp[0][0] = prefixSum[n-1]/n;
        for(int i=0;i<n;i++){
            dp[i] = (double)(prefixSum[n] - prefixSum[i])/(n-i);
            //cout<<dp[0][i]<<" ";
        }
        cout<<endl;
        
        for(int p=0; p<k-1; p++){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                   // int val = i>0? prefixSum[i-1]:0;
                    dp[i] = max(dp[i], dp[j] +(double)(prefixSum[j] - prefixSum[i])/(j-i));
                }
                cout<<dp[i]<<" ";
            }
        }

        // for(int i=0;i<=k;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0];

    }
};




/********* 2D DP **********************/

class Solution {
public:

    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefixSum(n,0);
        vector<vector<double>> dp(k+1,vector<double>(n,0));

        prefixSum[0] = nums[0];
        
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

       dp[0][0] = (double)prefixSum[n-1]/n;
        for(int i=1;i<n;i++){
            dp[0][i] = (double)(prefixSum[n-1] - prefixSum[i-1])/(n-i);
        }
        
        for(int p=1; p<k; p++){
            for(int i=0;i<n;i++){
                dp[p][i]=dp[p-1][i];
                for(int j=i+1;j<n;j++){
                   dp[p][i] = max(dp[p][i], dp[p-1][j] +(double)(prefixSum[j] - prefixSum[i]+(nums[i]-nums[j]))/(j-i));
                }
           
            }
        }

        
        return dp[k-1][0];

    }
};
