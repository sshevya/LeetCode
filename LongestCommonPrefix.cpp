class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int minl=INT_MAX;
        int n=strs.size();
        string mins;
        for(int i=0;i<n;i++){
            if(strs[i].length()<minl){
                mins=strs[i];
                minl=strs[i].length();
            }
            
        }
        
        for(int i=0;i<n;i++){
            string s=strs[i];
            
            for(int i=0;i<minl;i++){
                if(s[i]!=mins[i]){
                    minl=i;
                    break;
                }
            }
        }
        
        string s=mins.substr(0,minl);
        return s;
    }
};
