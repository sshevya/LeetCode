class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        int sign=1;
        string s="";

        if(numerator<0 ^ denominator < 0){
            s+="-";
        }
        if(numerator==0){
            s="0";
            return s;
        }
        long long int d=abs(denominator);
        long long int n=abs(numerator);
        unordered_map<long long int,long long int> m;
        long long int val=0;
        if(n>=d){
            long long int a=n/d;
            s+=to_string(a);
        }else{
            s+='0';
        }            val=n%d;

        if(val==0){
            return s;
        }
        s+=".";
        
        for(;val;val%=d){
            
            if(m.find(val)!=m.end()){
                s.insert(m[val],1,'(');
                s+=')';
                break;
            }
            m[val]=s.size();
            val=val*10;
            s+=to_string((val/d));
            
        }
        
        return s;
    }
};
