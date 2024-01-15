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
