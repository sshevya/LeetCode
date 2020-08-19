class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        
        int n=A.size();
        int l=INT_MAX;
        deque<int> dq;
        
        for(int i=0;i<n;i++){
            if(i>0){
                A[i]+=A[i-1];
            }
            
            if(A[i]>=K){
                l=min(l,i+1);
                
            }
            
            
            while(!dq.empty() && A[i]-A[dq.front()]>=K){
                l=min(l,i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && A[i]<=A[dq.back()])
                dq.pop_back();
            
                dq.push_back(i);
        
            
            
        }
       
        
        
        
        
        
        
    /* works only when no negative element;   
    while(end<n){
            while(curr_sum<=K && end<n){
                curr_sum+=A[end];
                end++;
            }
            
            while(curr_sum>K && start < n){
                l=min(end-start,l);
                curr_sum-=A[start];
                start++;
            }
        }
       */ 
        
        
        
        
        if(l==INT_MAX){
            return -1;
        }
        
        return l;
        
    }
};
