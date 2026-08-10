class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(const int& n: nums) total += n;

        if(total % 2 != 0) return false;

        int target = total / 2;

        vector<bool> memo(target + 1 , false);
        memo[0] = true;

        for(const int& num: nums){
            for(int i = target ; i >= num ; i--){
                if(memo[i - num]){
                    memo[i] = true;
                }
                if(memo[target]) return true;
            } 
        }
        return memo[target];
    }
};
