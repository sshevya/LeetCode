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
