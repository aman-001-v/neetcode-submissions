class Solution {
public:
    void passfunc(int n , vector<string>& memo , int row ,  vector<vector<string>>& result){
        if(row == n){
            result.push_back(memo);
            return;
        }
        for(int i = 0 ; i< n; i++){
            if(memo[row][i] == '0'){
                vector<string> memo_copy = memo;
                for(int j = 0; j < n ; j++){
                    
                    memo[row][j] = '.';
                    memo[j][i] = '.';
                    if(row - j >= 0 && i - j >= 0 && memo[row - j][i - j] != 'Q') memo[row - j][i - j] = '.';
                    if(row - j >= 0 && i + j < n && memo[row - j][i + j] != 'Q') memo[row - j][i + j] = '.';
                    if(row + j < n && i - j >= 0 && memo[row + j][i - j] != 'Q') memo[row + j][i - j] = '.';
                    if(row + j < n && i + j < n && memo[row + j][i + j] != 'Q') memo[row + j][i + j] = '.';
                }
                memo[row][i] = 'Q';
                passfunc(n , memo , row + 1 , result);
                memo = memo_copy;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> memo(n , string(n , '0')); 
        vector<vector<string>> result;
        passfunc(n , memo , 0 , result);
        return result;
    }
};