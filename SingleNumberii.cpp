class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<32;i++){
           
           int sum_of_1 = 0;
           for(int j=0; j<n; j++){
               sum_of_1 += (nums[j]>>i)&1;
           }

            sum_of_1%=3;

            ans |= sum_of_1<<i;
        }

        return ans;
    }
};
