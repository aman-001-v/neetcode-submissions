class Solution {
public:
    int dfs(vector<int>& stones , int i , vector<vector<int>>& memo , bool alice){
        if(i == stones.size()) return 0;

        if(memo[i][alice] != -1) return memo[i][alice];
        int total = 0;
        int res;
        if(alice) res = INT_MIN;
        else res = INT_MAX;
        for(int x = 0 ; x < 3 ; x++){
            if(i + x >= stones.size()) break;
            total += stones[i + x];
            if(alice) res = max(res , total + dfs(stones , i + x + 1 , memo , !alice));
            else res = min(res , -total + dfs(stones , i + x + 1, memo , !alice)); 
        }
        return memo[i][alice] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<vector<int>> memo(stoneValue.size() , vector<int>(2 , -1));
        int res = dfs(stoneValue , 0 , memo , true);
        if(res == 0) return "Tie";
        else if(res > 0) return "Alice";
        else return "Bob";
    }
};