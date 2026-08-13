class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> memo(n , 0);
        memo[0] = 1;
        for(int i = 0 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                memo[j] += memo[j - 1];
            }
        }
        return memo[n - 1];
    }
};