class Solution {
public:
    int findRight(vector<int> height, int i){
        
        int n=height.size();
        int maxm=0;
        for(int j=i+1;j<n;j++){
            maxm=max(maxm,j*min(height[j],height[i]));
        }
        
        return maxm;
        
    }
    int maxArea(vector<int>& height) {
        
        int max_ar=0,area;
        int n=height.size();
        
        int i=0;
        int j=n-1;
        max_ar=(j-i)*min(height[0],height[n-1]);
        
        while(i<j){
            
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
            
            area=(j-i)*min(height[i],height[j]);
            max_ar=max(max_ar,area);
            
            
        }
        
        
        return max_ar;
        
    }
};
