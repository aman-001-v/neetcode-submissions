class Solution {
public:
    void passfunc(unordered_map<int , int>& memo , vector<int>& curr , vector<vector<int>>& result){
        bool flag = true;
        for(auto i = memo.begin() ; i != memo.end() ; i++){
            if(i -> second != 0){
                flag = false;
                break;
            }
        }
        if(flag){
            result.push_back(curr);
            return;
        }
        for(auto i = memo.begin(); i != memo.end() ; i++){
            if(i -> second == 0) continue;
            int q = i -> first;
            i -> second--;
            // if(i -> second == 0){
            //     i = memo.erase(i);
            // }
            curr.push_back(q);
            passfunc(memo , curr , result);
            curr.pop_back();
            if(memo.contains(q)) memo[q]++;
            else memo[q] = 1;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> memo;
        for(int q: nums){
            if(memo.contains(q)) memo[q]++;
            else memo[q] = 1;
        }
        vector<vector<int>> result;
        vector<int> curr;
        passfunc(memo , curr , result);
        return result;

    }
};