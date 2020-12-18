class Solution {
public:
    
    //IMP, see what to do to avoid checking for duplicate vectors  
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
   
        
        
        vector<vector<int>> v;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int l,r;
        for(int i=0;i<n;i++){
            
            int l=i+1;
            int r=n-1;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            while(l<r){
               
             if(r<n-1 &&nums[r]==nums[r+1]){
                 r--;
                 continue;
             }
                 if(nums[i]+nums[l]+nums[r]>0){
                    r--;
                }else if (nums[i]+nums[l]+nums[r]<0){
                    l++;
                }else{
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[l]);
                    t.push_back(nums[r]);
                    
                    v.push_back(t);
                    l++;
                    r--;
                    
                }
                
            
            }
            
            
            
            
            
        }
        return v;
        
    }
};
