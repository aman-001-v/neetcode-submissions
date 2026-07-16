class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };


    unordered_set<pair<int,int>, pair_hash> memo;
    bool passfunc(vector<vector<char>>& board, string& word , int pos , int p , int q){
        if(pos == word.length()) return true;
       
        if(!memo.contains({p+1 , q}) && p + 1 < board.size() && board[p + 1][q] == word[pos]){
            memo.insert({p + 1 , q});
            bool flag = passfunc(board , word , pos + 1 , p + 1 , q);
            if(flag) return flag;
            memo.erase({p + 1 , q});
        }
        if(!memo.contains({p , q + 1}) && q + 1 < board[0].size() && board[p][q + 1] == word[pos]){
            memo.insert({p , q + 1});
            bool flag = passfunc(board , word , pos + 1 , p , q + 1);
            if(flag) return flag;
            memo.erase({p , q + 1});
        }
        if(!memo.contains({p , q - 1}) && q - 1 >= 0 && board[p][q - 1] == word[pos]){
            memo.insert({p , q - 1});
            bool flag = passfunc(board , word , pos + 1 , p , q - 1);
            if(flag) return flag;
            memo.erase({p , q - 1});
        }
        if(!memo.contains({p-1 , q}) && p - 1 >= 0 && board[p - 1][q] == word[pos]){
            memo.insert({p - 1 , q});
            bool flag = passfunc(board , word , pos + 1 , p - 1 , q);
            if(flag) return flag;
            memo.erase({p - 1 , q});
        }
       
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == word[0]){
                    memo.insert({i , j});
                    bool flag = passfunc(board , word , 1 , i ,j);
                    if(flag) return flag;
                    memo.erase({i, j});
                }
            }
        }
        return false;
    }
};