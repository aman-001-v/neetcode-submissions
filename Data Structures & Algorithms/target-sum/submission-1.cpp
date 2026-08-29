class Solution {
public:
    int dfs(vector<int>& nums , int pos , int target , vector<vector<int>>& dp , int total){
        if(pos == nums.size()){
            if(target == 0) return 1;
            else return 0;
        }

        if(abs(target) > total) return 0;

        if(dp[pos][abs(target)] == -1){
            int a = dfs(nums , pos + 1 , target + nums[pos] , dp , total - nums[pos]);
            int b = dfs(nums , pos + 1 , target - nums[pos] , dp , total - nums[pos]);

            dp[pos][abs(target)] = a + b;
        }

        return dp[pos][abs(target)];


    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int& q: nums) total += q;


        vector<vector<int>> dp(nums.size());

        int curr = total;

        for(int i = 0 ; i < dp.size() ; i++){
            dp[i] = vector<int>(curr + 1 , -1);
            curr -= nums[i];
        }

        return dfs(nums , 0 , target , dp , total);

    }
};