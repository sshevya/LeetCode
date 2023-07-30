class Solution {
public:
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};

    int DFSUtil(vector<vector<int>>& matrix, vector<vector<int>>& visited,  int x, int y, int path, int last){
        if(x<0 || y<0 || x>=matrix.size() || y>= matrix[0].size() ||matrix[x][y]<=last){
            return 0;
        }

        if(visited[x][y]!=-1){
            return visited[x][y];
        }
        //visited[x][y] = 1;
        int temp_path = INT_MIN;// = path;
        //last = matrix[x][y];
        for(int i=0;i<4;i++){
            temp_path = max(temp_path,DFSUtil(matrix, visited, x+X[i], y+Y[i], path, matrix[x][y])); 
        }
        
        //path = temp_path+1;
        visited[x][y] =  temp_path+1;
        return visited[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxPath = 1;
        int path ;
        vector<vector<int>> visited(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int last = INT_MIN;
                int path = 0;
                //cout<<"start "<<matrix[i][j]<<endl;
                path = DFSUtil(matrix, visited, i, j,0, last);
                maxPath = max(maxPath, path);
            }
        }
        return maxPath;
    }
};
