class Solution {
public:
   bool shouldswap(vector<int>& nums, int start, int index){
       for(int i=start;i<index;i++){
           if(nums[i]==nums[index]){
               return false;
           }     
       }
       return true;
   }
    
    
    void permut(vector<vector<int>>& v, vector<int>& nums,int index, int n){
        
        
        
        if(index==n){
            v.push_back(nums);
        }
        
        
        for(int i=index;i<n;i++){
            bool check=shouldswap(nums,index,i);
            if(check){
                swap(nums[index],nums[i]);
                permut(v,nums,index+1,n);
                swap(nums[index],nums[i]);
            }
        }
        
        
        
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        permut(v,nums,0,nums.size());
        return v;
    }
};
