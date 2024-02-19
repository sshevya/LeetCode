class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n==0){
            return {};
        }

        if(n==1){
            return {0};
        }

        vector<int> adj[n];
        vector<int> indeg(n,0);
        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            indeg[edges[i][0]]++;
            indeg[edges[i][1]]++;
        }

        queue<int> q;

        for(int i=0;i<n;i++){
            if(indeg[i]==1){
                q.push(i);
            }
        }

        while(!q.empty()){
            ans.clear();
            int size = q.size();
            for(int i=0;i<size;i++){
                int front = q.front();
                q.pop();
                ans.push_back(front);
                for(auto it=adj[front].begin();it!=adj[front].end();it++){
                    indeg[*it]--;
                    if(indeg[*it]==1){
                        q.push(*it);
                    }
                }
            }

        }
        return ans;
    }

};
