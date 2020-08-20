class Solution {
public:
    /****
    Linear solution faster
    for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
        }
        
        
        return -1;
        
    
    
    **/
    int binarysearch(vector<int>& nums, int l, int r, int target){
        
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums[mid]==target){
                    return mid;
                }
                if(nums[mid]<target){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int index=-1;
        int n=nums.size();
        if(n==1){
            if(target==nums[0]){
                return 0;
            }
            return -1;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){
                index=i;
            }
        }
       if(index!=-1 && target==nums[index]){
            return index;
        }
        if(index==-1){
        
            return binarysearch(nums,0,n-1,target);
        }        
        
        if(target<nums[0]){
            int l=index+1;
            int r= n-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums[mid]==target){
                    return mid;
                }
                if(nums[mid]<target){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }else{
            int l=0; 
            int r= index-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums[mid]==target){
                    return mid;
                }
                if(nums[mid]<target){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            
            
            
        }
        
        return -1;
        
        
    }
};
