class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> v;
        unordered_map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++ ){
            string s=strs[i];
            
            sort(s.begin(),s.end());
            m[s].push_back(strs[i]);
        }
        
        for(auto i=m.begin();i!=m.end();i++){
            v.push_back(i->second);
        }
        
        
        return v;
    }
};
