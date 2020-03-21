class Solution {
public:
    void subsetsutil(vector<int>& nums, vector<int>& subset, vector<vector<int>>& v, int index){
       
        //sort(subset.begin(),subset.end());
        if(std::find(v.begin(),v.end(),subset)==v.end()){
        v.push_back(subset);
    
        }
       
        for(int i=index;i<nums.size();i++){
            subset.push_back(nums[i]);
            subsetsutil(nums,subset,v,i+1);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>> v;
        vector<int> subset;
       sort(nums.begin(),nums.end());
        subsetsutil(nums,subset,v,0);
        return v;
    }
};
