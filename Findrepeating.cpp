class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     //SEE Interviewcake for sol using graph and linked list
     /** O(1) O(nlogn) if space optimized asked   
        int n=nums.size()-1;
        
        int l=1;
        int r=n;
        while(l<r){
        int mid=l+(r-l)/2;

                 int count_num=0;
   
        for(int i=0;i<n+1;i++){
            if(nums[i]>=l && nums[i]<=mid){
                count_num++;
                
            }
        }    
            
        int len=mid-l+1;
         //   cout<<count_num<<len;
        if(count_num> len){
            r=mid;
        }else{
            l=mid+1;
        }
            
            
            
        }
        
        
        
        return l;
 */
        
        
     /**  Solution 2 //O(n) space O(n) time
        unordered_map<int,int> s;
        
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(s.find(nums[i])!=s.end()){
                return nums[i];
            }else{
                s[nums[i]]=1;
            }
        }
        
        
        return -1;
    }**/
        //Solution 3 for readonly array O(1) space

    int n=nums.size();
    int hare=nums[nums[0]];
    int tortoise=nums[0];
    
        
        while(hare!=tortoise){
            tortoise=nums[tortoise];
            hare=nums[nums[hare]];
        }
        hare=0;
        while(hare!=tortoise){
            hare=nums[hare];
            tortoise=nums[tortoise];
        }
    return tortoise;
    }
    
    };
