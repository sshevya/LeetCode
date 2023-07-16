class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        /******** Solution 1 with dp
        //
        vector<int> dp(n,0);
        
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
        *********************/
        /**************
        // Solution2 without dp, more efficient
        int maxProfit1 = nums[0];
        int maxProfit2 = max(nums[0],nums[1]);
        int prev = maxProfit1;
        for(int i=2;i<n;i++){
            prev = maxProfit2; 
            maxProfit2 = max(maxProfit2, maxProfit1+nums[i]);
            maxProfit1 = prev;
          }
        return max(maxProfit1,maxProfit2);
    }
};
