class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n<=0){
            return false;
        }
        
        for(int i=0;i<32;i++){
            if((n>>i)&1){
                if(n==1<<i){
                    cout<<i;
                    return true;
                }else{
                    return false;
                }
            }
        }
        return false;
    }
};
