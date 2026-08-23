class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for(int stone : stones){
            for(int s = target; s >= stone; s--){
                dp[s] = dp[s] || dp[s - stone];
            }
        }

        int closest = 0;
        for(int s = target; s >= 0; s--){
            if(dp[s]){ closest = s; break; }
        }
        return total - 2 * closest;
    }
};