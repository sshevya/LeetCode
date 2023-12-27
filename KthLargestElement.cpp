class Solution {
public:

    void heapify(vector<int>& nums, int n,  int i){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < n && nums[left]<nums[smallest]){
            smallest = left;
        }
        
        if(right < n && nums[right]<nums[smallest]){
            smallest = right;
        }

        if(smallest != i){
            swap(nums[i], nums[smallest]);
            heapify(nums, n, smallest);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        //Build heap;
        for(int i = n/2-1;i>=0;i--){
            heapify(nums, n, i);
        }
        
        //heapify till array length is equal to k 
        for(int i=n-1;i>=k;i--){
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
            
        }

        return nums[0];
    }
};
