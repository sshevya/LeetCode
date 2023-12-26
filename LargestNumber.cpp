bool comparator(int a, int b){
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    }
class Solution {
public:


    
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();

        // int maxval = getMax(nums);

        // int exp=1;
        // while(maxval/exp>=1){
        //     exp*=10;
        // }
        // countSort(nums, exp);

        string s = "";
        sort(nums.begin(), nums.end(), comparator);
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
            
            s+=to_string(nums[i]);
            
        }

        if(nums[0]==0){
            return "0";
        }
        
        return s;
    }
};
