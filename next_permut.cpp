#include<bits/stdc++.h>
class Solution {
public:
    void swap(int* a, int* b) 
{ 
    if (*a == *b) 
        return; 
    *a ^= *b; 
    *b ^= *a; 
    *a ^= *b; 
} 
    void nextPermutation(vector<int>& nums) {
        
        
        int n=nums.size();
        int i=n-1;
        while(i>0&&nums[i]<=nums[i-1] ){
            i--;
        }
        if(i==0){
            sort(nums.begin(),nums.end());
            return;
        }
        
        
        int ind=i-1;
        int ind2=i;
    
        int next_greater=nums[i];
        
        for(int j=i+1;j<n;j++){
            if(nums[j]>nums[ind] && nums[j]<next_greater){
                next_greater=nums[j];
                ind2=j;
            }
        }
        
        swap(&nums[ind],&nums[ind2]);
        
        sort(nums.begin()+ind+1, nums.end());
        return;
        
        
        
        
        
        
    }
};
