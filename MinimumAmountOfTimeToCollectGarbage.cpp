class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int n = garbage.size();
        
        vector<int> pr(n-1,0);
        pr[0] = travel[0];
        int m = -1;
        int g = -1;
        int p = -1;
        int time = 0;
        for(int i=0;i<n;i++){
            string s = garbage[i];  
            for(int j=0;j<s.length();j++){
                if(s[j]=='G'){
                    g=i;
                }else if(s[j]=='M'){
                    m=i;
                }else{
                    p=i;
                }
                //1 min for each letter irrespective of letter
                time++;
            }    
           
        }

        for(int i=1;i<n-1;i++){
            pr[i]=pr[i-1]+travel[i];
        }

        time += m>0? pr[m-1]:0;
        time += g>0? pr[g-1]:0;
        time += p>0? pr[p-1]:0;
        
        return time;
    }
};
