class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start<n && nums[start]==0){
                    start++;
        }

        for(int i=start;i<=end;i++){
            if(start>=n){
                return;
            }
            if(nums[i]==0){
                while(start<n && nums[start]==0){
                    start++;
                } 
                if(start>=n){
                return;
            }               
                swap(nums[i], nums[start]);
                start++;
            }

        }

        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        while(end>=0 && nums[end]==2){
            end--;
        }
        
        for(int i=start;i<=end;i++){
            if(end<0){
                return;
            }
            if(nums[i]==2){
                while(end>=0 && nums[end]==2){
                    end--;
                }   
                if(end<0 || end<=i){
                return;
                }             
                swap(nums[i], nums[end]);
                end--;
            }

        }
        return;
    }
};
