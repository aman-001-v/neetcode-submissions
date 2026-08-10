class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo(nums.size() , -1);
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            int n = 0;
            for(int j = i + 1 ; j < nums.size() ; j++){
                if(nums[j] > nums[i]){
                    n = max(n , memo[j]);
                }
            }
            memo[i] = 1 + n;
        }
        int res = 0;
        for(int& q: memo) res = max(res , q);
        return res;
    }
};