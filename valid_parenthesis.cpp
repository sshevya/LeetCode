class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        int n=s.length();
        
        if(n<2 || n%2!=0){
            return false;
        }
        
        
        st.push(s[0]);
        int i=1;
        while(i<n || !st.empty()){
            
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                
                st.push(s[i]);
                i++;
            }
            else{
                if(st.empty()){
                    return false;
                }
                char a=st.top();
                st.pop();
                
                if((a=='(' && s[i]==')' )|| (a=='{' && s[i]=='}' ) || a=='[' && s[i]==']' ) {
                   
                    i++;
                }else{
            
                    return false;
                }
                
                
            }
        }
        
        return true;
        
    }
};
