class Solution {
public:
    int X[4]={1,-1,0,0};
    int Y[4]={0,0,1,-1};
    bool DFS(int in,int x, int y,int n,int m ,vector<vector<char>> & A,string B, vector<vector<bool>>& visited){


        if(in == B.size()){
            return 1;
        }
        int newx, newy;
        visited[x][y]=true;
        for(int i=0;i<4;i++){
            newx = x + X[i];
            newy = y + Y[i];

            if(newx>=0 && newx< n && newy>=0 && newy<m && visited[newx][newy]==false && A[newx][newy] == B[in]){
                if(DFS(in+1,newx, newy,n,m,A,B, visited)){
                    return 1;
                }
                visited[newx][newy]=0;
            }
        }

        return 0;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                vector<vector<bool>> v(n,vector<bool>(m,0));
                
                if(DFS(1,i,j,n,m,board,word, v)){
                    return 1;
                }
                }
            }
        }

        return 0;
        
    }
};





/****** second sol********/
class Solution {
public:
    bool backtrack(vector<vector<char>> &board, string word, int index, int i, int j, int n, int m){
        
        if(index == word.length()){
            return true;
        }
        if(i<0 || j<0 ||i>=n || j>=m ||  board[i][j]!=word[index] || board[i][j]=='*'){
            return false;
        }
        

        
    
        char c = board[i][j];
        board[i][j]='*';


        bool bottom = backtrack(board, word, index+1, i+1,j,n,m);
        bool top = backtrack(board, word, index+1, i-1,j,n,m);
        bool right = backtrack(board, word, index+1, i,j+1,n,m);
        bool left = backtrack(board, word, index+1, i,j-1,n,m);
        
        board[i][j]=c;
    return bottom || top || right || left;
    }
    
    
    
    
    bool exist(vector<vector<char>>& board, string word) {

        int n= board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    //vector<vector<bool>> visited(n, vector<bool>(m,false));

                    if(backtrack(board, word, 0, i, j,n,m)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
