class Solution {
public:
    int dfs(vector<vector<int>>& dp , int i , bool state , vector<int>& prices){
        if(i >= prices.size()) return 0;

        if(dp[i][(int)state] != INT_MIN) return dp[i][(int)state];

        int cooldown = dfs(dp , i + 1 , state , prices);
        if(state){
            int buy = dfs(dp , i + 1 , false , prices) - prices[i];
            dp[i][(int)state] = max(buy , cooldown);
        }else{
            int sell = dfs(dp , i + 2 , true , prices) + prices[i];
            dp[i][(int)state] = max(sell , cooldown);
        }

        return dp[i][(int)state];
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        else if(prices.size() == 2) return max(0 , prices[1] - prices[0]);

        vector<vector<int>> dp(prices.size() , vector<int>(2 , INT_MIN));

        return dfs(dp , 0 , true , prices);

    }
};