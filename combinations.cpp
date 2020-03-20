class Solution {
public:
    //if there are duplicates in array remove duplicates
    void bc(vector<vector<int>>& v, vector<int>& candidates,vector<int>& sum, int target, int i){
        if(target==0){
          //  sort(sum.begin(),sum.end());
        //    if(find(v.begin(),v.end(),sum)==v.end()){
            v.push_back(sum);
                return;
         //   }
            
        }
        if(target<0){
            return;
        }
        
        while(i<candidates.size() && target>=candidates[i]){
    
            sum.push_back(candidates[i]);
        
            bc(v,candidates,sum,target-candidates[i],i);
            i++;
                sum.pop_back();
        }
        
        
        
    }
    
    
    
    
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
            vector<int> sum;
        sort(candidates.begin(),candidates.end());
        bc(v,candidates,sum,target,0);
        return v;
        
    }
};
