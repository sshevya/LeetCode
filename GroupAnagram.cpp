/**************** Solution 1
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
**************/

/************* Solution 2

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
        //map<map<char,int>, vector<string>> anagrams;
        vector<vector<string>> ans; 
        unordered_map<string, vector<string>> anagrams2;
        int n = strs.size();
        for(int i=0;i<n;i++){
            unordered_map<char,int> m;

            for(int j=0;j<strs[i].length();j++){
                 m[strs[i][j]]+=1;

             }
            
            string sorted_strs="";
            for(int ch='a';ch<='z';ch++){
                if(m[ch]!=0){
                    sorted_strs+=to_string(m[ch]);
                    sorted_strs+=ch;
                }
            }
            cout<<sorted_strs<<endl;
            anagrams2[sorted_strs].push_back(strs[i]);
           

        }

        for(auto &it: anagrams2){
            vector<string> v = it.second;
            ans.push_back(v);
        }


        return ans;
    }



/****************
//Solution 3
//you can't use unordered_map as key but can use map as a key




class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
        map<map<char,int>, vector<string>> anagrams;
        vector<vector<string>> ans; 
        int n = strs.size();
        for(int i=0;i<n;i++){
            map<char,int> m;

            for(int j=0;j<strs[i].length();j++){
                m[strs[i][j]]+=1;
            }
            if(anagrams.find(m)!=anagrams.end()){
                anagrams[m].push_back(strs[i]);
            }else{
                vector<string> v;
                v.push_back(strs[i]);

                anagrams[m] = v;
            }
       
        }

        for(auto &it: anagrams){
            vector<string> v = it.second;
            ans.push_back(v);
        }


        return ans;
    }
};

**************/
***********/

