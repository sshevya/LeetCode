class Solution {
public:

    vector<int> findAnagrams(string s, string p) {
        
        int n = p.length();
        vector<int> v;

        if(n>s.length()){
            return v;
        }

        unordered_map<char,int> m1,m2;
        for(int i=0;i<n;i++){
            if(m1.find(p[i])!=m1.end()){
                m1[p[i]]+=1;
            }else{
                m1[p[i]]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(m2.find(s[i])!=m2.end()){
                m2[s[i]]+=1;
            }else{
                m2[s[i]]=1;
            }
        }

        for(int i=0;i<s.length()-n+1;i++){
            
            
            if(m1==m2){
                v.push_back(i);
            }
                
                if(m2[s[i]]==1){
                    m2.erase(s[i]);
                }else{
                    m2[s[i]]--;
                }
                if(m2.find(s[i+n])!=m2.end()){
                    m2[s[i+n]]+=1;
                }else{
                    m2[s[i+n]]=1;
                }

            
        }


    return v;

    }
};
