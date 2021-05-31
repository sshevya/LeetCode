class Solution {
public:
    
    
    
    double dfs(unordered_map<string,unordered_map<string,double>>& m, string to, string from, unordered_set<string>& visited){
        
        if(m.find(from)==m.end()){
            return -1.0;
        }
        
        
        if(m[from].find(to)!=m[from].end()){
            
            return m[from][to];
        }
        
        visited.insert(from);
        
        for(auto i= m[from].begin();i!=m[from].end();i++){
            
            if(visited.find(i->first)==visited.end()){
                visited.insert(i->first);
                
                double ans =dfs(m, to, i->first, visited);
                
                if(ans!=-1){
                    
                    return ans*(i->second);
                    
                }
                
            }
            
            
        }
            
        
       return -1.0; 
        
        
        
    }
    
    
    
    
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();
        unordered_map<string, unordered_map<string, double>> m;
        
        for(int i=0;i<n;i++){
            
            string from = equations[i][0];
            string to = equations[i][1];
            
            if(m.find(from)==m.end()){
                unordered_map<string,double> temp;
                
                temp[to] = values[i];
                
                m[from] = temp;
            }else{
                m[from][to]=values[i];
            }  
            if(m.find(to)==m.end()){
                unordered_map<string,double> temp;
                
                temp[from] = 1/values[i];
                
                m[to] = temp;
            }else{
                m[to][from]=1/values[i];
            }
            
            
        }
        
        int l = queries.size();
        vector<double> v;
        
        for(int i=0;i<l;i++){
            
            unordered_set<string> s;

            double ans = dfs(m,queries[i][1], queries[i][0], s);
            v.push_back(ans);
            
            
        }
        
        
        return v;
        
    }
};
