class Solution {
public:
    bool dfs(string& s , string& p , int i , int j , vector<vector<int>>& dp){

        if(i >= s.length() && j >= p.length()) return true;

        if(j >= p.length()) return false;

        if(i < s.length() && j < p.length() && dp[i][j] != -1) return dp[i][j];

        bool match = i < s.length() && (s[i] == p[j] || p[j] == '.');

        if(j < p.length() - 1 && p[j + 1] == '*'){
            dp[i][j] = dfs(s , p , i , j + 2 , dp) || (match && dfs(s , p , i + 1 , j , dp));
            return dp[i][j];
        }
        if(match){
            dp[i][j] = dfs(s , p , i + 1 , j + 1 , dp);
            return dp[i][j];
        }
        dp[i][j] = false;
        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
        return dfs(s , p , 0 , 0 , dp);
    }
};