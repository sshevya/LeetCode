class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int prefixSum = 0;
        unordered_map<int, int> m;
        int count =0;

        for(int i=0;i<n;i++){
            prefixSum+=nums[i];

            if(prefixSum==k){
                count++;
            }
            if(m.find(prefixSum-k)!=m.end()){
                count+=m[prefixSum-k];
            }
            m[prefixSum]++;
        }
        

        return count;
    }
};
