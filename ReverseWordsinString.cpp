class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> v;
        string temps="";
        int i=0;
        int len=s.length();
        if(len==0){
            return temps;
        }
        while(i<len){
        
        while( i<len && s[i]!=' '){
            temps+=s[i];
            i++;
        }
            if(temps!=""){
        v.push_back(temps);
            }
        if(i!=len && s[i]==' '){
            i++;
            temps="";
        }
        }
        
      reverse(v.begin(),v.end());
    string news="";
        if(v.size()==0){
            return temps;
        }
        for(int i=0;i<v.size()-1;i++){
            news+=v[i];
            news+=" ";
        }
        news+=v[v.size()-1];
        return news;
    }
};
