class Solution {
public:
      //Here array might contain duplicates which might result in formation of same solution more thanm once, hence before includin we check if thde vector is already prsent
    void bc(vector<vector<int>>& v, vector<int>& candidates,vector<int>& sum, int target, int i){
        if(target==0){
            sort(sum.begin(),sum.end());
          if(find(v.begin(),v.end(),sum)==v.end()){
            v.push_back(sum);
                return;
            }
            
        }
        if(target<0){
            return;
        }
        
        while(i<candidates.size() && target>=candidates[i]){ 
            //int temp=candidates[i];
            sum.push_back(candidates[i]);
            //vector<int>::iterator it = candidates.begin(); 
            //candidates.erase(it); 
  
            bc(v,candidates,sum,target-candidates[i],i+1);
            i++;
            sum.pop_back();
            //candidates.insert(candidates.begin(),temp);
        }
        
        
        
    }
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          vector<vector<int>> v;
            vector<int> sum;
        sort(candidates.begin(),candidates.end());
        
        bc(v,candidates,sum,target,0);
        return v;
      
        
        
    }
};
