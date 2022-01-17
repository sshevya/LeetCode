class Solution {
public:
    
    void floodfill( vector<vector<char>>& board, int m, int n, int x, int y){
        
        if(x<0 || y<0 || x>=m || y>=n){
            return;
        }
            
        if(board[x][y]!='-'){
            return;
        }
        
        board[x][y]='O';
        
        floodfill(board,m,n,x+1,y);
        floodfill(board,m,n,x,y+1);

        floodfill(board,m,n,x,y-1);
        floodfill(board,m,n,x-1,y);
      
        
        
    }
    
    
    
    void solve(vector<vector<char>>& board) {
        
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='-';
                }
            }
        }
        
        
        
        for(int i=0;i<m;i++){
            if(board[i][0]=='-'){
                floodfill(board,m,n,i,0);
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='-'){
                floodfill(board,m,n,i,n-1);
            }
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='-'){
                floodfill(board,m,n,0,i);
            }
        }
        for(int i=0;i<n;i++){
            if(board[m-1][i]=='-'){
                floodfill(board,m,n,m-1,i);
            }
        }
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='-'){
                    board[i][j]='X';
                }
            }
        }
        
        
    }
};
