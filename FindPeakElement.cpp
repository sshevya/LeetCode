class Solution {
public:
    int binarySearch(vector<int>& nums, int i, int j){
        int mid = i+(j-i)/2;
        int ans1=-1;
        int ans2 = -1;
        if(i<0 || j>= nums.size() || j<i){
            return -1;
        }
        cout<<i<<j<<" ";

        if(mid==0 && i==j ){
            if(nums[0]>nums[1])            
                return mid;
            return -1;
        }

        if(mid==nums.size()-1 && i==j){
            if(nums[mid]>nums[mid-1])            
                return mid;
            return -1;
        }

        if(mid>0 && mid<nums.size()-1 && nums[mid]>nums[mid-1] && nums[mid]> nums[mid+1]){
           return mid;
        }

        ans1 = binarySearch(nums,i,mid-1);
        ans2 = binarySearch(nums,mid+1,j);
        if(ans1 == -1 || ((ans1==0 || ans1==nums.size()-1)  && ans2<nums.size()-1 && ans2>0)){
            return ans2;
        }
        
        return ans1;
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;

        if(n==1){
            return 0;
        }

        if(n==2){
            return nums[0]>=nums[1]?0:1;
        }

        int ans = binarySearch(nums,0,n-1);

        return ans>=0?ans:0;
    }
};
