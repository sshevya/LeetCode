class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int min_l = INT_MAX ;
        int currsum = 0;
        int start = 0;
        int end = 0;
        for(int i=0;i<n;i++){
             currsum+=nums[i];

            while(currsum>=target){
                int len = i - start +1;

                min_l = min(min_l, len);
                currsum-=nums[start];
                start++;

            }
        }
        
        return min_l==INT_MAX?0 : min_l;
    }
};
