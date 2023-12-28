class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int count1 = 0 ;
        int count2 = 0;
        int val1 = 0;
        int val2 = 0;
        for(int i=0;i<n;i++){
            if(count1==0 && nums[i]!=val2){
                count1 = 1;
                val1 = nums[i];
            }
            else if(count2==0 && nums[i]!=val1){
                count2 = 1;
                val2 = nums[i];
            }
            else if(nums[i]==val1){
                count1++;
            }
            else if(nums[i]==val2){
                count2++;
            }else{
                count1--;
                count2--;
            }
            cout<<count2<<" ";
        }

        //cout<<val1<<" "<<val2;

        vector<int> result;

        int count = n/3;
        count1 = 0;
        count2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==val1){
                count1++;
            }
            else if(nums[i]==val2){
                count2++;
            }
        }

        if(count1>count){
             result.push_back(val1);
        }
        if(count2>count){
            result.push_back(val2);
        }

        return result;
    }
};
