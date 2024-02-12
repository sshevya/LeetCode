class Solution {
public:
    int maxScore(string s) {
        int l = s.length();
        
        int c0 = 0;
        int c1 = 1;
        int ans = INT_MIN;


        for(int i=0;i<l-1;i++){
            if(s[i]=='0'){
                c0++;
            }else{
                c1++;
            }

            ans = max(ans, c0-c1);
            
        }

        c1+=(s[l-1]=='1');

        return ans+c1;
    }
};
