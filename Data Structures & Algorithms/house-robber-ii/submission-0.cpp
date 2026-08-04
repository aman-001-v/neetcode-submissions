class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 4){
            int maxnum = 0;
            for(int i = 0 ; i < nums.size() ; i++) if(maxnum < nums[i]) maxnum = nums[i];
            return maxnum;
        }
        vector<int> ed = nums;
        nums[nums.size() - 1] = 0;
        ed.erase(ed.begin());
        ed.push_back(0);

        for(int i = nums.size() - 4 ; i >= 0 ; i--){
            nums[i] += max(nums[i + 2] , nums[i + 3]);
            ed[i] += max(ed[i + 2] , ed[i + 3]);
        }
        return max(max(ed[0] , ed[1]), max(nums[0] , nums[1]));
    }
};