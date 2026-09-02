class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> memo(n + 1 , vector<int>(m + 1, -1));
        memo[n][m] = 0;
        for(int i = 0 ; i < word1.length() ; i++){
            memo[i][m] = n - i;
        }
        for(int i = 0 ; i < word2.length() ; i++){
            memo[n][i] = m - i;
        }
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = m - 1 ; j >= 0 ; j--){
                if(word1[i] == word2[j]){
                    memo[i][j] = memo[i + 1][j + 1];
                }
                else{
                    memo[i][j] = 1 + min({memo[i][j + 1] , memo[i + 1][j] , memo[i + 1][j + 1]});
                }
            }
        }
        return memo[0][0];
    }
};