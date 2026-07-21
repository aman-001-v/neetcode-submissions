class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> memo(n , true);
        vector<int> memo2(n , 0);
        for(int i = 0 ; i < trust.size(); i++){
            memo[trust[i][0] - 1] = false;
            memo2[trust[i][1] - 1]++;
        }

        for(int i = 0; i< n ; i++){
            if(memo[i] && memo2[i] == n - 1) return i + 1;
        }
        return -1;
    }
};