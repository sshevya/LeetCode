class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
     
        int n=words.size();
                vector<int> v;

        if(n==0){
            return v;
        }
                int l=words[0].length();

        if(n*l>s.length()){
            return v;
        }
        
        
        
        
        unordered_map<string, int> m;
        for(int i=0;i<n;i++){
            m[words[i]]+=1;
        }
        int ind;
        for(int i=0;i<s.length()-n*l+1;i++){
           unordered_map<string, int> tempm=m; 
            
            for(int j=i;j<i+n*l;j+=l){
                int start=i;
                string subs=s.substr(j,l);
                 
                //unordered_map<string,int>::iterator itr=tempm.begin();
                //itr++;
                if(tempm.find(subs)!=tempm.end()){
                    tempm[subs]-=1;
                   // cout<<tempm[subs]<<i;
                    if(tempm[subs]==0){
                        tempm.erase(subs);
                    }
                   // cout<<subs<<i;
                    if(tempm.size()==0){
                        v.push_back(i);
                    }
                }else{
                    
                    break;
                }
                
            
            }
            
        }
        
       
                
        return v;
        
        
    }
};
