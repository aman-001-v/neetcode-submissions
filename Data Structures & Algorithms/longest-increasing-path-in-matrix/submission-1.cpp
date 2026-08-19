class Solution {
public:
    int dfs(vector<vector<int>>& matrix , int i , int j , vector<vector<int>>& dp){
        if(dp[i][j] != -1) return dp[i][j];

        int left = 0 , right = 0 , up = 0 , down = 0;

        if(i > 0 && matrix[i - 1][j] > matrix[i][j]){
            up = dfs(matrix , i - 1 , j , dp);
        }
        if(i < matrix.size() - 1 && matrix[i + 1][j] > matrix[i][j]){
            down = dfs(matrix , i + 1, j , dp);
        }
        if(j > 0 && matrix[i][j - 1] > matrix[i][j]){
            left = dfs(matrix , i , j - 1 , dp);
        }
        if(j < matrix[0].size() - 1 && matrix[i][j + 1] > matrix[i][j]){
            right = dfs(matrix , i , j + 1 , dp);
        }
        return dp[i][j] = max({left , right , up , down}) + 1;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size() , vector<int>(matrix[0].size() , -1));
        
        int maxn = 0;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                int num = dfs(matrix , i , j , dp);
                maxn = max(maxn , num);
            }
        }
        return maxn;
    }
};