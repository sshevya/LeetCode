class Solution {
public:
    
     bool isValidRow(vector<vector<char>> & board, int x, int y){
        
        
        for(int i=0;i<9;i++){
            
            if(i!=x && board[x][y]==board[i][y]){
                
                return false;
            }
            
        }
        
        return true;
        
    }
    
    
    bool isValidCol(vector<vector<char>> & board, int x, int y){
        
        
        for(int i=0;i<9;i++){
            
            if(i!=y && board[x][y]==board[x][i]){

                return false;
            }
            
        }
        
        return true;
        
    }
    
    
    bool isValidMat(vector<vector<char>> & board, int x, int y){
        
        int startRow= x - x%3;
        int startCol= y - y%3;
        for(int i=0;i<3;i++){
            
           for(int j=0;j<3;j++){
               if(!(i+startRow==x&&j+startCol==y)){
               if(board[x][y]==board[i+startRow][j+startCol]){
                   return false;
               }
               }
           }
            
        }
        
        return true;
    }
    
    
    bool isValid(vector<vector<char>> & board, int x, int y){
        if( isValidRow(board,x,y) && isValidCol(board,x,y) && isValidMat(board,x,y)){
            return true;
        }
        return false;
    }
    
    bool isUnassigned(vector<vector<char>> & board, int &x ,int &y){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    x=i;
                    y=j;
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool solve(vector<vector<char>>& board){
        int x,y;
        if(!isUnassigned(board,x,y)){
            return true;
        }
        
        
        for(int i=1;i<=9;i++){
            string s=to_string(i);
            char c=s[0];
            board[x][y]=c;
            
            if(isValid(board,x,y)){
                if(solve(board)){
                
                    return true;
                }
            }
                board[x][y]='.';
            
            
            
        }
        
        
        
         
        
        
        
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
        
    }
};
