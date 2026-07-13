class Solution {
public:
    void passfunc(vector<int>& nums , int pos , vector<int>& curr , vector<vector<int>>& result){
        result.push_back(curr);

        for(int i = pos ; i < nums.size() ; i++){
            curr.push_back(nums[i]);
            passfunc(nums , i + 1 , curr , result);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        passfunc(nums , 0 , curr , result);
        return result;
    }
};