class Solution {
public:
    
   
    
    
    string getPermutation(int n, int k) {
        
        string s="";
        for(int i=1;i<=n;i++){
            s+=to_string(i);
        }
        
        int i=0;
        
        do{
            if(i==k-1){
                break;
            }
            i++;
        }while(next_permutation(s.begin(),s.end()));
       
        
        
        return s;
    }
};
