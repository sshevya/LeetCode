class Solution {
public:
    string countAndSay(int n) {
        
        
        string s="1";
        if(n==1){
            return s;
        }
        
        vector<string> v;
        v.push_back(s);
        for(int i=0;i<n;i++){
            string s= v[i];
            string new_s="";
            int l=s.length();
            int count=1;
            if(l==1){
                new_s+="1";
                new_s+=s[0];
            }else{
            for(int j=1;j<l;j++){
                if(s[j-1]==s[j]){
                    count++;
                }else{
                    new_s+=to_string(count);
                    count=1;
                    new_s+=s[j-1];
                }    
            }
                
                new_s+=to_string(count);
                    new_s+=s[l-1];
            }
            v.push_back(new_s);
        
        }
        
    
        return v[n-1];
        
    }
};
