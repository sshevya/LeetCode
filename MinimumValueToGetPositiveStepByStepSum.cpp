class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();

        int val = INT_MAX;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            val = min(val, sum);
        }
        
        return val<0?abs(val)+1:1;
    }
};
