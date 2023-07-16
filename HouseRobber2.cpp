class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        
        
        vector<int> dp_1(n,0);
        vector<int> dp_2(n,0);
        dp_1[0] = nums[0];
        dp_1[1] = nums[0];

        dp_2[0]=0;
        dp_2[1] = nums[1];        
        if(n==2){
            return max(dp_1[1],dp_2[1]);
        }
        for(int i=2;i<n-1;i++){
           dp_1[i] = max(dp_1[i-1], dp_1[i-2]+nums[i]);
           dp_2[i] = max(dp_2[i-1], dp_2[i-2]+nums[i]);
        }

        dp_1[n-1] = max(dp_1[n-2], dp_1[n-3]);
        dp_2[n-1] = max(dp_2[n-2], dp_2[n-3]+nums[n-1]);
        

        return max(dp_1[n-1],dp_2[n-1]);

    }
};
