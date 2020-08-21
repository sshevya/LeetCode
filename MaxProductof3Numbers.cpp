//O(n) sol
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int maxp=1;
        int a=INT_MIN,b=INT_MIN ,c=INT_MIN,d=INT_MAX,e=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(nums[i]<=e){
                d=e;
                e=nums[i];
            }else if(nums[i]<=d){
                d=nums[i];
            }
            
            if(nums[i]>=a){
                c=b;
                b=a;
                a=nums[i];
            }else if(nums[i]>=b){
                c=b;
                b=nums[i];
            }else if(nums[i]>=c){
                c=nums[i];
            }
            
        }        
        return max(a*b*c,a*d*e);
    }
};


/*** O(nlogn)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxp=1;
        int n=nums.size();
        maxp=max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
        return maxp;
    }
};
***/
