class Solution {
public:
    
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }

        if(n==2){
            return min(nums[0], nums[1]);
        }
        int i=0;
        int j=n-1;

        int mid = i+(j-i)/2;

        if(nums[0]<=nums[mid] && nums[mid]<=nums[n-1]){
            return nums[0];
        }
        if(nums[0]>=nums[mid] && nums[mid]>=nums[n-1]){
            return nums[n-1];
        }


        while(i<=j){
            int mid = i+(j-i)/2;
            cout<<i<<" "<<j<<endl;
            if(mid==0){
                return min(nums[mid], nums[mid+1]);
            }
            if(mid==n-1){
                return min(nums[mid], nums[mid-1]);
            }
            if(nums[mid]<=nums[mid-1] && nums[mid]<=nums[mid+1]){
                return nums[mid];
            }
            if(nums[0]>nums[mid]){
                j=mid-1;
            }
            else{
                i=mid+1;
            }

        }

        return -1;
    }
};
