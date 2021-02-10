class Solution {
public:
   
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        if(nums.size()<4){
            return res;
        }
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<pair<int,int>>> m;
        int sum=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                sum=nums[i]+nums[j];
                if(m.find(target-sum)!= m.end()){
                 for(int k=0;k<m[target-sum].size();k++){

                    int a=m[target-sum][k].first;
                    int b=m[target-sum][k].second;
                    
                    if(a!=i && a!=j && b!=i && b!=j){
                    vector<int> v;
                    v.push_back(nums[a]);
                    v.push_back(nums[b]);
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    sort(v.begin(),v.end());
                    if(find(res.begin(), res.end(), v)==res.end()){
                        res.push_back(v);
                    }
                    }
                    
                }  
                }
                m[sum].push_back(make_pair(i,j));
                
                
                
                
                
            }
           
        }
         return res;
        
        
    }
};
