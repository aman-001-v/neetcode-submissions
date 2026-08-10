class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long> memo(target + 1 , 0);
        memo[0] = 1;
        for(int i = 1 ; i <= target ; i++){
            for(int num: nums){
                if(num <= i){
                    memo[i] += memo[i - num];
                    if(memo[i] > INT_MAX) memo[i] = INT_MAX;
                }
            }
        }
        return memo[target];
    }
};