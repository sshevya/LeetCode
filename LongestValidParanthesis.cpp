class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n=s.length();
        int i=0,res=0;
        /*while(s[i]==')'){
            i++;
        }*/
        st.push(-1);
       // st.push(i);
        while(i<n){
            
            
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                
                if(!st.empty()){
                    res=max(res,i-st.top());
                }else{
                    st.push(i);
                }
                
                
            }
            i++;
  
            
        }
        
        
        
        
        
           return res;
 
        
    }
};
