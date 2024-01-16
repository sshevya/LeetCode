class Solution {
public:
    
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        for(int i=0;i<32;i++){
            int setbits = 0;
            for(int j=0;j<n;j++){
                setbits += (nums[j]>>i)&1;
            }
            
            ans += setbits * (n-setbits);
        }

        return ans;
    }
};
