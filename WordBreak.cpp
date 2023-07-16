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
