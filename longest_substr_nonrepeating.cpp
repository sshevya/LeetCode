#include<bits/stdc++.h>
class Solution {

public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0){
            return 0;
        }
        int len=1;
        
        unordered_map<char,int> st;
        for(int i=0;i<n;i++){
            st[s[i]]=-1;
        }
        int start=0;
        int end=0;
        //st[s[0]]=0;
        while(end<=n-1){
            
         
            /*  start=max(start,st[s[end]]+1);
             len=max(len,end-start+1);
            
            st[s[end]]=end;
            end++;*/
            
             if(st.find(s[end])==st.end()){
                 
              st[s[end]]=end;
               len=max(len,end-start+1);
               end++;
             }else{
                start=st[s[end]]+1;
                st[s[end]]=end;
               // len=max(len,end-start+1);
               end++;
             }

               
           
            
        }
        
        return len;
        
    }
};
