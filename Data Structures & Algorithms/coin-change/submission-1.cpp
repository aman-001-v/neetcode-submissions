class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        sort(coins.begin() , coins.end());
        vector<int> memo(amount + 1 , -1);

        memo[0] = 0;

        for(int i = 0 ; i < amount + 1 ; i++){
            if(i < coins[0]){
                continue;
            }
            int minCoins = INT_MAX;
            for(int j = 0 ; j < coins.size() ; j++){
                if(i - coins[j] < 0) break;
                if(memo[i - coins[j]] < minCoins && memo[i - coins[j]] != -1) minCoins = memo[i - coins[j]];
            }
            if(minCoins != INT_MAX ) memo[i] = minCoins + 1;
            
        }


        return memo[amount];
    }
};