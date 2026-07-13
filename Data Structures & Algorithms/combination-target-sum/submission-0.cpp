class Solution {
public:
    void dfs(vector<int>& candidates , int pos , int& target , vector<int>& curr , vector<vector<int>>& result , int sum){
        if(sum == target){
            result.push_back(curr);
            return;
        }
        if(sum > target) return;
        for(int i = pos; i< candidates.size() ; i++){
            curr.push_back(candidates[i]);
            dfs(candidates , i, target , curr , result , sum + candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        dfs(candidates , 0 , target , curr, result , 0);
        return result;
    }
};