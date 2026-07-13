class Solution {
public:
    void passfunc(vector<int>& candidates , int& target , int pos , vector<int>& curr , vector<vector<int>>& result , int sum){
        if(sum == target){
            result.push_back(curr);
            return;
        }

        for(int i = pos ; i < candidates.size() ; i++){
            if(i > pos && candidates[i] == candidates[i - 1]) continue;
            if(sum > target) break;
            curr.push_back(candidates[i]);
            passfunc(candidates , target , i + 1 , curr , result , sum + candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        passfunc(candidates , target , 0 , curr, result , 0);
        return result;
    }
};