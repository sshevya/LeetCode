class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> m;
        int sum = 0;
        int max_l = 0;
        int len =0;

        for(int i=0;i<n;i++){
            
            if(nums[i]==0){
                sum-=1;
            }else{
                sum+=1;
            }
            cout<<sum<<" "<<i<<" ";
            if(sum == 0){
                cout<<"here";
                len = i+1;
                max_l = max(max_l, len);
            }    
            else if(m.find(sum)!=m.end()){
                len = i-m[sum];

                if(len>max_l){
                    max_l = len;
                }
            }else{
                m[sum] = i;
            }
            
        }

        return max_l;
    }
};
