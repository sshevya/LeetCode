class Solution {
public:
    int getMaxVal(vector<int>& nums){
        int n = nums.size();
        int maxVal = INT_MIN;
        for(int i=0;i<n;i++){
            maxVal = max(maxVal, nums[i]);
        }

        return maxVal;
    }

    //countsort based on digit
    void countSort(vector<int>& nums, int exp){
        int n = nums.size();

        //digits always between 0 to 9
        vector<int> count(10, 0);
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            count[(nums[i]/exp)%10]++;
        }

        //cumulative sum to find original index
        for(int i=1;i<10;i++){
            count[i]+=count[i-1];
        }
        
        //forming ans array, starting from last so order of index is preserved(stable sorting)
        for(int i=n-1;i>=0;i--){
            ans[count[(nums[i]/exp)%10]-1] = nums[i];
            count[(nums[i]/exp)%10]--;
        }

        for(int i=0;i<n;i++){
            nums[i]=ans[i];
        }

    }

    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2){
            return 0;
        }

        int maxVal = getMaxVal(nums);

        for(int exp = 1; maxVal/exp>0; exp*=10){
            countSort(nums, exp);
        }

        int maxDiff = INT_MIN;
        for(int i=1;i<n;i++){
            int diff = nums[i]-nums[i-1];
            maxDiff = max(maxDiff, diff);
        }
        
        return maxDiff;
    }
};
