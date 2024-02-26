class Solution {
public:

    void DFS(int s, vector<int> adj[], vector<int> &visited){

        visited[s] = 1;

        for(auto i = adj[s].begin(); i!=adj[s].end();i++){
            if(visited[*i]==0){
                DFS(*i, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        vector<int> visited(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                DFS(i, adj, visited);
                count++;
            }
        }


        return count;
    }
};
