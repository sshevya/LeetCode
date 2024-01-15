/********* Solution with optimization using memoization and bit manipulation*******/

class Solution {
public:
    bool solve(int z,int &n,int x,int &s,int y,vector<int> &v,vector<int> &dp){
        if(y==4){
            return true;
        }
        if(z == (1<<n)-1){
            return true;
        }
        if(dp[z] != -1)return dp[z];
        bool a = false;
        for(int i = 0; i < n; i++){
            if((z&(1<<i))==0){
                x += v[i];
                if(x<s){
                    a |= solve(z|(1<<i),n,x,s,y,v,dp);
                }else if(s==x){
                    a |= solve(z|(1<<i),n,0,s,y+1,v,dp);
                }
                x -= v[i];
            }
        }
        return dp[z] = a;
    }
    bool makesquare(vector<int>& v) {
        int s = 0;
        for(auto &i: v){
            s += i;
        }
        if(s%4)return false;
        s /= 4;
        int n = v.size();
        sort(v.begin(),v.end());
        vector<int> dp((1<<n)+15,-1);
        return solve(0,n,0,s,0,v,dp);
    }
};



/********* wo optimization *****************/

class Solution {
public:
    bool backtrack(vector<bool> &visited,  vector<int> &v, int ind, int sum, int side_count, int target){
        
        if(side_count==4){
            return true;
        }

        if(sum==target){
            return backtrack(visited, v, 0, 0, side_count+1, target);
        }
        
        if(sum<0 || ind==v.size() || side_count>4){
            return false;
        }

        
        
        for(int i =ind; i<v.size(); i++){  
            if(v[i]+sum>target){
                return false;
            }
            if(!visited[i] && v[i]+sum<=target){
                visited[i] = true;
                if(backtrack(visited, v, i+1, sum+v[i], side_count, target)){
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();

        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=matchsticks[i];
        }
        if(n<4 || sum%4!=0){
            return false;
        }

        int side = sum/4;

        vector<bool> visited(n,false);
        sort(matchsticks.begin(), matchsticks.end());
        
        return   backtrack(visited, matchsticks, 0, 0, 0, side);
;
    }
};
