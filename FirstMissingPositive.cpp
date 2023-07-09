class Solution {
public:

 /**Second approach by heap***/
    // void heapify(int i, int last, vector<int>& nums){
    //     int left = 2*i+1;
    //     int right = 2*i+2;
    //     int n = nums.size();
    //     int smallest = i;
        
    //     if(left<last && nums[left]<nums[i]){
    //         smallest = left;
    //     }

    //     if(right<last && nums[right]<nums[i]){
    //         smallest = right;
    //     }
    //     if(smallest!=i){
            
    //         swap(nums[i],nums[smallest]);
    //         heapify(smallest, last, nums);
    //     }

    // }
    
    int firstMissingPositive(vector<int>& nums) {
        int missing = 1;
        int n = nums.size();
        
        int last = n-1;
        while(last>0 && nums[last]<=0){
            last--;
        }
        for(int i=0;i<=last;i++){
            if(i==last){
                break;
            }
            if(nums[i]<=0){
                swap(nums[i],nums[last]);
                while(last>=0 && nums[last]<=0){
                    last--;
             }
            }
        }
        if(last==0){
            return nums[0]==1?2:1;
        }
        for(int i =0;i<=last;i++){
                
            if(nums[i]>0 && nums[i]<=n){
                if(nums[nums[i]-1]>0){
                    nums[nums[i]-1]*=-1;
                }
                else if(nums[nums[i]-1]==0){
                    nums[nums[i]-1]=INT_MIN;
                }
            }else if(nums[i]<0 && nums[i]>=-1*n){
                int ind = -1*nums[i];
                if(nums[ind-1]>0){
                nums[ind-1]*=-1;
                }
                else if(nums[ind-1]==0){
                    nums[ind-1]=INT_MIN;
                }
            }   
        }

        
        int i= 0;
        for(i=0;i<=last;i++){
            if(nums[i]>0){
                break;
            }
            
        }

        while(i<n && nums[i]==INT_MIN){
            i++;
        }
        
        return i+1;
    }
};
