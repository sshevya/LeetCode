class Solution {
public:
    int trap(vector<int>& A) {
        int n=A.size();
       if(n<3){
           return 0;
       }
        int sum=0;
        
        /**for(int i=1;i<n-1;i++){
            
            int left=A[i],right=A[i];
            for(int j=0;j<i;j++){
                left=max(left,A[j]);
            }
            for(int j=i+1;j<n;j++){
                right=max(right,A[j]);
            }
            
            sum+=min(left,right)-A[i];
            
        }
        **/
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0]=A[0];
        right[n-1]=A[n-1];
    
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],A[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],A[i]);
        }
        
        for(int i=0;i<n;i++){
            
            
            sum+=min(left[i],right[i])-A[i];
            
            
        }
        
        
        
        
        return sum;
    }
};
