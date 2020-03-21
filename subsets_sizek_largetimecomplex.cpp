class Solution {
public:
    
    void bc(vector<vector<int>>& v, vector<int>& subset, vector<int> arr, int n, int k, int i){
      
        if(k==0){
            v.push_back(subset);
            return;
        }
        while(i<n){
            subset.push_back(arr[i]);
            bc(v,subset,arr,n,k-1,i+1);
            i++;
            subset.pop_back();
        }
        
        
    }
    
    
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> v;
        vector<int> subset,arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        bc(v,subset,arr,n,k,0);
        return v;
    }
};
