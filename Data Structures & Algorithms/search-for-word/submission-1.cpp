class Solution {
public:

    bool passfunc(vector<vector<char>>& board, string& word , int pos , int p , int q){
        if(pos == word.length()) return true;
        
        if(p + 1 < board.size() && board[p + 1][q] == word[pos]){
            board[p + 1][q] = '#';
            bool flag = passfunc(board , word , pos + 1 , p + 1 , q);
            if(flag) return flag;
            board[p + 1][q] = word[pos];
            
        }
        if(q + 1 < board[0].size() && board[p][q + 1] == word[pos]){
            board[p][q + 1] = '#';
            bool flag = passfunc(board , word , pos + 1 , p , q + 1);
            if(flag) return flag;
            board[p][q + 1] = word[pos];
            
        }
        if(q - 1 >= 0 && board[p][q - 1] == word[pos]){
            board[p][q - 1] = '#';
            bool flag = passfunc(board , word , pos + 1 , p , q - 1);
            if(flag) return flag;
            board[p][q - 1] = word[pos];
        }
        if(p - 1 >= 0 && board[p - 1][q] == word[pos]){
            board[p - 1][q] = '#';
            bool flag = passfunc(board , word , pos + 1 , p - 1 , q);
            if(flag) return flag;
            board[p - 1][q] = word[pos];
        }
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == word[0]){
                    board[i][j] = '#';
                    bool flag = passfunc(board , word , 1 , i ,j);
                    if(flag) return flag;
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};