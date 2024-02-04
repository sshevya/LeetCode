class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> m;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];

            int rem = sum%k;
            if((rem==0 && sum!=0 && i>=1) || (sum==0 && i>=1)){
                return true;
            }
            if(m.find(rem)!=m.end()){
                
                int j = m[rem];
                if(i-j>=2){
                    return true;
                }
            }else{
                m[rem] = i;

            }

        }

        return false;
    }
};
