class Solution {
public:
    bool passfunc(vector<int>& nums , int i , vector<int>& memo){
        if(i >= nums.size() - 1){
            return true;
        }
        if(memo[i] != -1) return memo[i];
        if(nums[i] == 0){
            memo[i] = 0;
            return false;
        }

        for(int j = 1 ; j <= nums[i] ; j++){
            bool t = passfunc(nums , i + j , memo);
            if(t){
                memo[i] = 1;
                return true;
            }
        }
        memo[i] = 0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size() , -1);
        return passfunc(nums , 0 , memo);
    }
};
