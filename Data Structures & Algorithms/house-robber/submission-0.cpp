class Solution {
public:

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[0] , nums[1]);
        else if(nums.size() == 3) return max(nums[0] + nums[2] , nums[1]);
        nums.push_back(0);
        for(int i = nums.size() - 4 ; i>=0 ; i--){
            nums[i] += max(nums[i + 2] , nums[i + 3]);
        }
        return max(nums[0] , nums[1]);
    }
};