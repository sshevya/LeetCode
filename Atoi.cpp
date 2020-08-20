class Solution {
public:
    int myAtoi(string str) {
     
        int n=str.length();
        int i=0;
        int sign=1;
        while(str[i]==' '){
            i++;
        }
        if(str[i]=='+'){
            sign=1;
            i++;
        } else if( str[i]=='-'){
            sign=-1;
            i++;
        }
        
        int val=0;
        while(i<n && str[i]>='0' && str[i]<='9'){
            //cout<<val<<" ";
            if(val> INT_MAX/10 || (val==INT_MAX/10 && str[i]>'7')){
                if(sign==1){
                    return INT_MAX;
                }
                return INT_MIN;
            }
            val=val*10+(str[i]-'0');
            i++;
        }
        
    
        return sign*val;
    }
};
