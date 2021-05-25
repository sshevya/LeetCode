class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        int n = emails.size();
        
        unordered_map<string,int> m;
        
        
        
        for(int i=0;i<n;i++){
        string s = "";
            bool check =0;
            for(int j=0;j<emails[i].length();j++){
                if(emails[i][j]=='@'){
                    check = 1;
                }
                
                
                if(emails[i][j]=='+'){
                    while(emails[i][j]!='@'){
                        j++;
                        
                    }
                    check = 1;
                    s+='@';
                }else{
                    if(!check && emails[i][j]!='.'){
                        s+=emails[i][j];
                    }
                    
                    if(check){
                        s+=emails[i][j];

                    }
                    
                }  
            }
            
            m[s]+=1;
            
            
        }
        
        
        
        return m.size();
    }
};
