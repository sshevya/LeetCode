class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int n=nums.size();
        int l=INT_MAX;
        int start=0;
        int end=0;
        int sum=0;
        if(n==0){
            return 0;
        }
        while(end<n){
            while(sum<s && end<n){
                sum+=nums[end];
                end++;
               // l=min(l,end-start);
            }
            while(sum>=s && start<n){
                l=min(l,end-start);
                sum-=nums[start++];
                
            }
            
            
        }
        
        if(l==INT_MAX ){
            return 0;
        }
        
        return l;
        
    }
};
