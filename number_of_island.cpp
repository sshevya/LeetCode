class Solution {
public:
    
    int X[4]={1,-1,0,0};
    int Y[4]={0,0,1,-1};
    int count=0;
    
    void DFS(int x, int y,int n,int m,vector<vector<bool>> &visited, vector<vector<char>>& grid){
        
            visited[x][y]=1;
            for(int i=0;i<4;i++){
                if(x+X[i]>=0 && x+X[i]<n && y+Y[i]>=0 && y+Y[i]<m){
                            //            cout<<y+Y[i]<<" ";

                if(grid[x+X[i]][y+Y[i]]=='1' && visited[x+X[i]][y+Y[i]]==0){
                    DFS(x+X[i],y+Y[i],n, m,visited, grid);
                }
                }
            
            
            
        }
        return;
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        if(n==0){
            return 0;
        }
        
        int m=grid[0].size();
        if(m==0){
            return 0;
        }
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                                    

                    DFS(i,j,n,m,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
