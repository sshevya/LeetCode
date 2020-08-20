class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size();
        int m[60]={0};
        int count=0;
        for(int i=0;i<n;i++){
            m[time[i]%60]+=1;
        }
    
        count+=m[0]*(m[0]-1)/2;
        for(int i=1;i<30;i++)
            count+=m[i]*m[60-i];
            count+=m[30]*(m[30]-1)/2;
        
        return count;
        
    }
};
