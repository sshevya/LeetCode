class Solution {
public:
    void rec(int remaining, int opencount, string s, vector<string>& v){
       if(remaining==0 && opencount==0){
           v.push_back(s);
       }
        
        if(opencount>0){
            s+=")";
            rec(remaining,opencount-1,s,v);
            s.erase(s.size()-1);
        }
        
         if(remaining>0){
            s+="(";
            rec(remaining-1,opencount+1,s,v);
            s.erase(s.size()-1);
        }
        
        
           
    }
    
    
    
    
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> v;
        string s="";
        rec(n,0,s,v);
  
        
        return v;
        
    }
};
