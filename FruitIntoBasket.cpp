class Solution {
public:
    int totalFruit(vector<int>& tree) {
        
        unordered_map<int,int> m;
        int n = tree.size();
        int index = 0;
        int j =0,len=0;
        for(int i =0;i<n;i++){
            m[tree[i]]+=1;
                while(m.size()>2 && j<=i){
                    
                    
                        m[tree[j]]--;
                    if(m[tree[j]]==0){
                        m.erase(tree[j]);
                        
                    }
                    
                    j++;
                }   
            
            
            len = max(len, i-j+1);
            
            
            
            
        }
        
        
        
      return len;
        
        
    }
};
