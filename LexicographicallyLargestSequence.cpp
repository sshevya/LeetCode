class Solution {
public:

    bool bc(vector<int> &ans, vector<int>& check, int n,int i){
        if(i==2*n-1){
            
            return true;
        }
        if(ans[i]!=0){
            return bc(ans, check, n, i+1);
        }
        for(int j = n;j>0;j--){
            if(check[j]==1){
                continue;
            }   

            if(j!=1 && (i+j>=2*n-1 || ans[i+j])){
                
                continue;
            }

            ans[i]=j;
            check[j]=1;
            if(j!=1)
                ans[i+j]=j;
            if(bc(ans,check, n,i+1)){
                    return true;
             }
            ans[i]=0;
            if(j!=1)
                ans[i+j]=0;
            check[j]=0;
            
        }

        cout<<"here"<<" ";
        return false;

    }




    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1,0);
        vector<int> check(n+1,0);
        bc(ans,check, n, 0);
        return ans;


    }
};
