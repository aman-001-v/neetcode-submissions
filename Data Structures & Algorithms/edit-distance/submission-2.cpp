class Solution {
public:
    int passfunc(string word1 , string word2 , int i , int j , vector<vector<int>>& memo){
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        if(j == word2.length()){
            return memo[i][j] = word1.length() - i;
        }
        else if(i == word1.length()){
            return memo[i][j] = word2.length() - j;
        }
        if(word1[i] == word2[j]){
            return memo[i][j] = passfunc(word1 , word2 , i + 1 , j + 1 , memo);
        }
        int a = passfunc(word1 , word2 , i , j + 1 , memo);

        int b = passfunc(word1 , word2 , i + 1 , j , memo);

        int c = passfunc(word1 , word2 , i + 1 , j + 1 , memo);

        return memo[i][j] = 1 + min({a , b , c});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.length() + 1 , vector<int>(word2.length() + 1 , -1));
        return passfunc(word1 , word2 , 0 , 0 , memo);
    }
};