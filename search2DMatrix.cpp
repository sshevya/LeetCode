
class Solution {
public:
    bool binarysearch(vector<int> v, int l, int r, int target){
         
        while(l<=r){
            int mid=l+(r-l)/2;
            if(v[mid]==target){
                return true;
            }
            if(v[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
            
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        if(n==0 ){
            return false;
        }
        int m=matrix[0].size();
        if( m==0){
            return false;
        }
       int  t=0;
        int b=n-1;
        
        while(t<=b){
            int mid=t+(b-t)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][m-1]){
    
                return binarysearch(matrix[mid],0,m-1,target);
            }
            
            if(target<matrix[mid][0]){
                b=mid-1;
            }else{
                t=mid+1;
            }
            
            
        }
        return false;
    }
};



/***class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //O(n^2) space
        int n=matrix.size();
        if(n==0 ){
            return false;
        }
        int m=matrix[0].size();
        
        vector<int> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(matrix[i][j]);
            }
        }
        
        int len=v.size();
        int l=0,r=len-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(v[mid]==target){
                return true;
            }
            if(v[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
            
        }
        
        
        return false;
        
    }
};
****/
