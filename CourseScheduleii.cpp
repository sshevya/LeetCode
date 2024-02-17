class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indeg(numCourses,0);
        vector<int> ans, temp;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }

        queue<int> q;
        
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for(auto i=adj[v].begin(); i!= adj[v].end();i++){
                indeg[*i]--;
                if(indeg[*i]==0){
                    q.push(*i);
                }
            }
        }

        if(ans.size()==numCourses){
            return ans;
        }
        
        return temp;
    }
};
