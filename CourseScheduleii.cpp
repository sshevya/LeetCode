


/***************** Kahn's Algo ********/



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


/************** Graph coloring, instead of marking visited 0,1. mark -1 to keep track of rec stack in the same vector ********/


class Solution {
public:

    bool DFSUtil(int v, vector<int> adj[], vector<int> &visited, vector<int> &recStack){

        if(visited[v]==1){
            return true;
        }

        
        visited[v] = -1;
        //cout<<"here"<<v<<endl;
        for(auto i=adj[v].begin();i!=adj[v].end();i++){
            //cout<<"adj: "<<*i;
            if(visited[*i]==0 && DFSUtil(*i, adj, visited, recStack)){
                //cout<<"Kkk";
                return true;
              }else if(visited[*i]==-1){
                 return true;
             }
        }
        
        visited[v] = 1;

        recStack.insert(recStack.begin(),v);
        //cout<<"jhh";
        return false;
        
    }



    vector<int> DFS(int numCourses, vector<int> adj[]){
        
        vector<int> ans;
        vector<int> recStack;
        vector<int> visited(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0 && DFSUtil(i, adj, visited, recStack)){
                return ans; 
            }
        }

        
        return recStack;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> ans = DFS(numCourses, adj);
        
        return ans;
    }
};
