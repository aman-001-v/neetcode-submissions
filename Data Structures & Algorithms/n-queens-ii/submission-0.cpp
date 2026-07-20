class Solution {
public:
    void passfunc(int n , int row , vector<bool>& column , vector<bool>& dia , vector<bool>& antidia , int& result){
        if(row == n){
            result++;
            return;
        }
        for(int i = 0; i < n; i++){
            if(!column[i] && !dia[row - i + n - 1] && !antidia[row + i]){
                column[i] = true;
                dia[row - i + n - 1] = true;
                antidia[row + i] = true;
                passfunc(n , row + 1 , column , dia , antidia , result);
                column[i] = false;
                dia[row - i + n - 1] = false;
                antidia[row + i] = false;
            }
        }
    }
    int totalNQueens(int n) {
        vector<bool> column(n , false);
        vector<bool> dia(2*n - 1 , false);
        vector<bool> antidia(2*n - 1 , false);
        int result = 0;
        passfunc(n , 0 , column , dia , antidia , result);
        return result;
        
    }
};