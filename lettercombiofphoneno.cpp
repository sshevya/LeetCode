class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.length();
      
        string table[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" }; 
        
        vector<string> op;
          if(n==0){
            return op;
        }
        queue<string> q;
        q.push(table[0]);
       /*
        this is like bfs, a,d,g,j etc are st same level; similarly b,e,h etc; 
       */
       while(!q.empty()){
           string s=q.front();
           q.pop();
           if(s.length()==n){
               op.push_back(s);
           }
           else{
               
               for(auto letter: table[digits[s.length()]-'0']){
                   q.push(s+letter);
               }
               
               
           }
           
           
           
       }
        
        
       return op; 
        
    }
};
