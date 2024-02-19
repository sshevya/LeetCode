class Solution {
public:
    
    void DFS(unordered_map<string, multiset<string>> &adj, string airport, vector<string> &result){

        
        while(!adj[airport].empty()){
            string next = *adj[airport].begin();
            adj[airport].erase(adj[airport].begin());
            DFS(adj, next, result);
        }
        result.push_back(airport);
        return;
    }
    
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string, multiset<string>> adj;

        for(int i=0;i<n;i++){
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        vector<string> result;
        DFS(adj, "JFK", result);
        reverse(result.begin(),result.end());
        return result;
    }
};
