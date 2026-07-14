class Solution {
public:
    void passfunc(vector<int>& nums , vector<vector<int>>& result , vector<int>& curr){
        if(nums.empty()){
            result.push_back(curr);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            curr.push_back(nums[0]);
            nums.erase(nums.begin());
            passfunc(nums , result , curr);
            nums.push_back(curr[curr.size() - 1]);
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        passfunc(nums , result , curr);
        return result;
    }
};