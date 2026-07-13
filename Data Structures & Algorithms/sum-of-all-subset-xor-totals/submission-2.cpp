class Solution {
public:
    void dfs(vector<int>& nums , int pos, int& ans, int curr){
        if(pos == nums.size()){
            ans += curr;
            return;
        }
        dfs(nums , pos + 1 , ans , curr ^ nums[pos]);
        dfs(nums , pos + 1 , ans , curr);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        dfs(nums , 0 , ans , 0);
        return ans;
    }
};