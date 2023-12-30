class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorAll = 0;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            xorAll = xorAll^nums[i];
        }
        int val1 = 0;
        int val2 = 0;

        int rightMostSetBit = xorAll&(~(xorAll-1));

        for(int i =0 ;i<n;i++){
            if((nums[i]&rightMostSetBit)>0){
                val1 = val1^nums[i];
            }else{
                val2 = val2^nums[i];
            }
        }

        ans.push_back(val1);
        ans.push_back(val2);
        return ans;
    }
};
