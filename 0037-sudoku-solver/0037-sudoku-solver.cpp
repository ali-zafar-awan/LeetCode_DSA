class Solution {
public:
    bool isValid(vector<vector<char>>& board,int val, int r, int c){
        for(int i=0;i<9;i++){
            if(board[r][i]==val){
                return false;
            }
            if(board[i][c]==val){
                return false;
            }
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==val){
                return false;
            }
        }
        return true;
    }
    bool sudoku(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k = 1; k<=9;k++){
                        char val = '0'+k;
                        if(isValid(board,val,i,j)){
                            board[i][j]=val;
                            if(sudoku(board)){
                                return true;
                            }else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board);
    }
};