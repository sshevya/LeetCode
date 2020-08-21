class Solution {
public:
    bool isCycle(int v,vector<int> adj[], vector<bool>& recstack, vector<bool>& visited){
        if(!visited[v]){
        visited[v]=true;
            recstack[v]=true;
        for(auto i=adj[v].begin();i!=adj[v].end();i++){
            
            if(!visited[*i] && isCycle(*i,adj,recstack,visited)){
                    return true;
                
            }else if(recstack[*i]){
            return true;
        }
            
        
        }
    }
    recstack[v]=false;
    return false;
        
    }
    
bool DFS(vector<int> adj[], int n){
    
    vector<bool> visited(n,0);
    vector<bool> recstack(n,0);
    for(int i=0;i<n;i++){
        if(isCycle(i,adj,recstack,visited)){
            return true;
        }
    }
    return false;
}
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<int> adj[numCourses];
        
        for(int i=0;i<n;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            
        }
        
        if(DFS(adj,numCourses)){
            return false;
        }
        return true;
        
        
    }
};
