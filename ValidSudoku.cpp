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
    
    
    
    
    
    
    
    
    
    
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    
                    if(!(isValidRow(board,i,j) && isValidCol(board,i,j) && isValidMat(board,i,j))){
                        return false;
                    }
                }
            }
        }
        
        return true;
        
    }
};
