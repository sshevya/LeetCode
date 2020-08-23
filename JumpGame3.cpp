class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector< int> dp(n,0);
        queue<int> q;
        q.push(start);
        dp[start]=1;
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
            
    
                if(arr[top]==0){
                    return true;
                }
                if(top+arr[top]<n && !dp[top+arr[top]]){
                    q.push(top+arr[top]);
                    dp[top]=1;
                }
                if(top-arr[top]>=0 && !dp[top-arr[top]]){
                    q.push(top-arr[top]);
                }
            
            
        }
        
        
            return false;
            
        
        
        
        
        
        
    }
};
