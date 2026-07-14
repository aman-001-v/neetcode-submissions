class Solution {
public:
    void passfunc(vector<int>& nums , int pos , vector<int>& curr , vector<vector<int>>& result){

        result.push_back(curr);

        for(int i = pos ; i < nums.size() ; i++){
            
            int n = i;
            int count = 0;
            while(n + 1 < nums.size() && nums[n] == nums[n + 1]) n++;
            for(int j = i ; j <= n ; j++){
                count++;
                curr.push_back(nums[j]);
                passfunc(nums , n + 1 , curr , result);
            }
            for(int j = 0 ; j < count ; j++){
                curr.pop_back();
            }

            i = n;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> result;
        vector<int> curr;
        passfunc(nums , 0 , curr , result);
        return result;
    }
};