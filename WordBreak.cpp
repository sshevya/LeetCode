class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;

        int n = s.length();
        int m = wordDict.size();

        for(int i=0;i<m;i++){
            dict.insert(wordDict[i]);
        }
        
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j = i-1;j>=0;j--){
                if(dp[j]){
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!=dict.end()){
                        dp[i]=1;
                        break;
                    }

                }
            }
        }

        
        return dp[n];
    }
};


/******** solution 2***********/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> m;
        int n= wordDict.size();
        int l = s.length();

        for(int i=0;i<n;i++){
            m[wordDict[i]]=1;
        }

        vector<vector<int>> dp(l+1, vector<int>(l+1,0));
        
        for(int i=0;i<=l;i++){
            //j shouldn't be till l because it represents length
            for(int j=0;j<=l-i;j++){
                string subs=s.substr(i,j);
                if(m.find(subs)!=m.end()){
                    dp[i][i+j]=1;
                    if(dp[0][i]){
                        dp[0][i+j] = 1;
                    }
                    
                }
            }
        }
    
        
        return dp[0][l];
        
    }
};
