class Solution {
public:
    int passfunc(vector<int>& nums , int l , int r , vector<vector<int>>& memo){
        if(memo[l][r] != -1) return memo[l][r];
        if(r - l == 2){
            return memo[l][r] = nums[l] * nums[l + 1] * nums[r];
        }
        else if(r - l == 1 || r - l == 0) return memo[l][r] = 0;

        int res = 0;

        for(int i = l + 1 ; i < r ; i++){
            int t = passfunc(nums , l , i , memo) + passfunc(nums , i , r , memo);
            res = max(res , t + nums[l] * nums[i] * nums[r]);
        }
        return memo[l][r] = res;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin() , 1);
        vector<vector<int>> memo(nums.size() , vector<int>(nums.size() , -1));
        return passfunc(nums , 0 , nums.size() - 1 , memo);
    }
};