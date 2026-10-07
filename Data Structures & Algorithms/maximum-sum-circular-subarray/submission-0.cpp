class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currmax = nums[0];
        int globalmax = nums[0];
        int currmin = nums[0];
        int globalmin = nums[0];
        int total = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            total += nums[i];
            currmax = max(nums[i] , currmax += nums[i]);
            globalmax = max(currmax , globalmax);

            currmin = min(nums[i] , currmin += nums[i]);
            globalmin = min(currmin , globalmin);
        }

        if(globalmax < 0) return globalmax;
        else return max(globalmax , total - globalmin);
    }
};