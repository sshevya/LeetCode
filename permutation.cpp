/****** Backtrack ******/
class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& currans,vector<int>& nums, int i){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        if(i>=nums.size()){
            return;
        }
        for(int j = i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            backtrack(ans,currans,nums,i+1);
            swap(nums[i],nums[j]);
        
        }


    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> currans;
    backtrack(ans,currans,nums,0);
    return ans;    
    }
};





/*using function*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        vector<int> mv;
        mv.resize(n);
        do{
            mv=nums;
            v.push_back(mv);
        }
        while(next_permutation(nums.begin(),nums.end()));
        
        
        
     return v;   
    }
};
