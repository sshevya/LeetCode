class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int min_v=INT_MAX;
        int val;
        for(int i=0;i<n;i++){
            int l=i+1;
            int r=n-1;
            
            while(l<r){
            int diff=abs(nums[i]+nums[l]+nums[r]-target);
                if(diff<min_v){
                    min_v=diff;
                    
                    val=nums[i]+nums[l]+nums[r];
                }
                
                if(nums[i]+nums[l]+nums[r]<target){
                    l++;
                }else if(nums[i]+nums[l]+nums[r]>target){
                    r--;
                }else{
                    return target;
                }
                    
                
                
            }
            
            
        }
        return val;
        
        
    }
};
