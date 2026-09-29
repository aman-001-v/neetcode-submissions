class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int t = 0;
        int n = nums.size();
        for(int i = 0 ; i <= n ; i++){
            t += i;
        }
        int t2 = 0;
        for(int i = 0 ; i < n ; i++){
            t2 += nums[i];
        }
        return t - t2;
    }
};