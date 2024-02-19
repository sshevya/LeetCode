class Solution {
public:

    bool DFS(string source, string destination, unordered_map<string, vector<pair<string,double>>> &m, map<string,int> &visited,double &ans){

        if(m.find(source)==m.end()){
            return false;
        }
        visited[source] = 1;
        for(auto it=m[source].begin();it!=m[source].end();it++){
            
            if(visited[(*it).first]!=1){

                string currdes = (*it).first;
                            
                ans = ans * (*it).second;
                if(currdes==destination){
                    return true;
                }
                if(DFS(currdes, destination, m, visited, ans)){
                    return true;
                }else{
                    ans = ans / (*it).second;
                }
            }
            
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string,double>>> m;
        vector<double> res;
        for(int i=0;i<n;i++){
            m[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            m[equations[i][1]].push_back(make_pair(equations[i][0], 1/values[i]));

        }
        for(int i=0;i<queries.size();i++){
            if(m.find(queries[i][0])==m.end()){
                res.push_back(-1);
            }
            else{

                double ans = 1;
                map<string,int> visited;
                if((queries[i][1]==queries[i][0]) || DFS(queries[i][0], queries[i][1], m, visited, ans))
                    res.push_back(ans);
                else{
                    res.push_back(-1);
                }
            }
        }
        return res;
    }
};
