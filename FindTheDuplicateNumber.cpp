
/********** Bit Manipulation **************/



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        
        for(int bit =0; bit<32 ;bit ++){
            
            int x=0;
            int y=0;

            for(int i=0;i<n;i++){
                if((nums[i] & (1<<bit))!=0){
                    x+=1;
                }
                if(i>=1 && (i & (1<<bit))!=0){
                    y+=1;
                }
            }

            if(x>y){
                ans = ans |= 1<<bit;
            }
        }

        return ans;
    }
};

/**********  Hare Tortoise Algo (Slow and Fast Pointer) **************/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int  slow = 0;
        int fast = 0;

        while(1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast){
                break;
            }
        }

        slow = 0;

        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

