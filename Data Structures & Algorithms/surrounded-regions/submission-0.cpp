class Solution {
public:
    void dfs(vector<vector<char>>& board ,int i , int j){
        board[i][j] = 'a';
        if(i > 0 && board[i - 1][j] == 'O') dfs(board , i - 1 , j);
        if(i < board.size() - 1 && board[i + 1][j] == 'O') dfs(board , i + 1 , j);
        if(j > 0 && board[i][j - 1] == 'O') dfs(board , i , j - 1);
        if(j < board[0].size() - 1 && board[i][j + 1] == 'O') dfs(board , i , j + 1); 
    }
    void solve(vector<vector<char>>& board) {
        for(int i = 0 ; i < board.size() ; i++){
            if(board[i][0] == 'O'){
                dfs(board , i , 0);
            }
            if(board[i][board[0].size() - 1] == 'O'){
                dfs(board , i , board[0].size() - 1);
            }
            
        }
        for(int j = 0 ; j < board[0].size() ; j++){
            if(board[0][j] == 'O'){
                dfs(board , 0 , j);
            }
            if(board[board.size() - 1][j] == 'O'){
                dfs(board , board.size() - 1 , j);
            }

        }

        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'a') board[i][j] = 'O';
            }
        }
    }
};