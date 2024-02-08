class Solution {
public:

    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int n = nums.size();
        int xor_n = 0;

        for(int i=0;i<n;i++){
            xor_n = xor_n^nums[i];
        }

        for(int i=n-1;i>=0;i--){
            int num = 0;

            for(int i=0;i<maximumBit;i++){
                if(xor_n&(1<<i)){
                    continue;
                }else{
                    num |= (1<<i);
                }
            }

            ans.push_back(num);
            xor_n = xor_n^nums[i];
        }

        return ans;
    }
};
