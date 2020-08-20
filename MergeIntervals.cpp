class Solution {
public:
    bool comparator(const vector<int>& v1, const vector<int>& v2){
        return v1[0]>=v2[0];
    }
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        
        int n=intervals.size();
        if(n==0){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> v;
        v.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            int  n=v.size();
            
            if(intervals[i][0]<=v[n-1][1]){
                if(intervals[i][0]<=v[n-1][0] && intervals[i][1]<v[n-1][0]){
                    v.push_back(intervals[i]);
                }
                else if(intervals[i][0]<=v[n-1][0] && intervals[i][1]>=v[n-1][1]){
                v[n-1][1]=intervals[i][1];
                }
                else if(intervals[i][0]<=v[n-1][0] && intervals[i][1]>=v[n-1][0]){
                    v[n-1][0]=intervals[n-1][0];
                }else if(intervals[i][0]>v[n-1][0] && intervals[i][1]>v[n-1][1])
                       v[n-1][1]=intervals[i][1];
            
            }else{
                v.push_back(intervals[i]);
            }
            
            
        }
        
        
        
        
        return v;
        
    }
};
