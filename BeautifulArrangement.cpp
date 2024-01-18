class Solution {
public:
    void backtrack(vector<int> &v, int n, int curr_num, int &ans){
        if(curr_num>n){
            ans++;
            return;
        }

        for(int i=1; i<=n; i++){
            if(v[i]==0 && (curr_num%i==0 || i%curr_num==0)){
                v[i] = curr_num;
                backtrack(v, n, curr_num+1, ans);
                v[i]=0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> v(n+1,0);
        int ans = 0;

        backtrack(v, n, 1, ans);
        return ans;
    }
};
