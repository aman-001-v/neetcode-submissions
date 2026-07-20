class Solution {
public:
    void passfunc(int n , vector<bool>& column , vector<bool>& diagonal , vector<bool>& anti_diagonal , vector<vector<string>>& result , vector<string>& memo , int row){
        if(row == n){
            result.push_back(memo);
            return;
        }

        for(int i = 0 ; i < n ; i++){
            if(!column[i] && !diagonal[row - i + n - 1] && !anti_diagonal[row + i]){
                column[i] = true;
                diagonal[row-i + n - 1] = true;
                anti_diagonal[row + i] = true;
                memo[row][i] = 'Q';
                passfunc(n , column , diagonal , anti_diagonal , result , memo , row + 1);
                memo[row][i] = '.';
                column[i] = false;
                diagonal[row-i + n - 1] = false;
                anti_diagonal[row + i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> column(n , false);
        vector<bool> diagonal(2*n - 1 , false);
        vector<bool> anti_diagonal(2*n - 1 , false);
        vector<vector<string>> result;
        vector<string> memo(n , string(n , '.'));
        passfunc(n , column , diagonal , anti_diagonal , result , memo , 0);
        return result;
    }
};