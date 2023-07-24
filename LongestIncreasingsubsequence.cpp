class Solution {
public:
/***O(nlogn)*****, O(n^2) dp)*****/

    int BS(vector<int>& dp, int target){
        int l = 0;
        int r = dp.size();
        int ans = 0;
        while(l<=r){
            
            int mid = l+(r-l)/2;

            if(dp[mid]>=target){
                ans = mid;
                r = mid-1;
            }else{
                l= mid+1;
            }
        }

        return ans;
    }


    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;

        vector<int> ans;

        ans.push_back(nums[0]);

        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }else{
                int ind = BS(ans, nums[i]);
                cout<<i<<" "<<ind<<" ";
                ans[ind] = nums[i];
            }
        }

    return ans.size();
    }
};
