class Solution {
public:
    int numSquares(int n) {
        vector<int> memo(n + 1 , 0);
        for(int i = 1 ; i <=n ; i++){
            int n = INT_MAX;
            for(int s = 1 ; s * s <= i; s++){
                n = min(n , memo[i - (s * s)]);
            }
            memo[i] = n + 1;
        }
        return memo[n];
    }
};