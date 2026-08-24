class Solution {
public:
    int dfs(vector<int>& piles , int i , bool alice , int m , vector<vector<vector<int>>>& dp){
        if(i >= piles.size()) return 0;
        if(dp[i][m][alice] != -1) return dp[i][m][alice];
        int res;
        if(alice) res = 0;
        else res = INT_MAX;

        int total = 0;

        for(int x = 1 ; x <= 2 * m; x++){
            if(i + x > piles.size()) break;

            total += piles[i + x - 1];

            if(alice) res = max(res , total + dfs(piles , i + x , false , max(m , x) , dp));
            else res = min(res , dfs(piles , i + x , true , max(m , x) , dp));
        }
        dp[i][m][alice] = res;
        return res;
    }

    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> dp(piles.size(),vector<vector<int>>(piles.size() + 1 , vector<int>(2 , -1)));
        return dfs(piles , 0 , true , 1 , dp);
    }
};