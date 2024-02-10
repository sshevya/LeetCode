class Solution {
public:

    int kadane(vector<int> nums, int k){
        int n = nums.size();

        int max_so_far = INT_MIN;
        int max_ending_here = 0;
        int max_val = nums[0];
        set<int> s ;
        s.insert(0);

        for(int i=0; i<n;i++){
            max_ending_here += nums[i];

            //finding sum smaller than k
            set<int>::iterator it = s.lower_bound(max_ending_here - k);
            
            if(it!=s.end()){
                max_so_far = max(max_so_far, max_ending_here - *it);
            }
            s.insert(max_ending_here);
           
        }

        return max_so_far;
    }
    
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        
        //map<int, int> m;
        int maxans = INT_MIN;
        int j =0;

        for(int l=0;l<m;l++){ 
            vector<int> prefixSum(n,0); 
            for(int r=l;r<m;r++){           
                for(int i=0;i<n;i++){
                    
                    prefixSum[i] +=  matrix[i][r];
                }   

                    int sum = kadane(prefixSum, k);
                    cout<<l<<" "<<r<<" "<<sum<<endl;
                    if(sum>maxans && sum<=k){
                        maxans = sum;
                    
                }
            }
        }

       return maxans;

    }
};
