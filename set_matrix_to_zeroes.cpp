class Solution {
public:


    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool check_row = false;
        bool check_col = false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && matrix[i][j]==0){
                    check_row = true;
                }
                if(j==0 && matrix[i][j]==0){
                    check_col = true;
                }
                if(matrix[i][j]==0){
                   matrix[0][j]=-9999;
                   matrix[i][0]=-9999;
                }
            }
        }

        for(int i=1;i<n;i++){
            if(matrix[i][0] == -9999){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }

        for(int i=1;i<m;i++){
            if(matrix[0][i] == -9999){
                for(int j=0;j<n;j++){
                    matrix[j][i]=0;
                }
            }
        }
        

        if(check_row){
            for(int i=0;i<m;i++){
                matrix[0][i]=0;  
            }
        }

        if(check_col){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;  
            }
        }

        return;
    }
};
