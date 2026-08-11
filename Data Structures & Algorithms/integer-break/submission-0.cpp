class Solution {
public:
    int integerBreak(int n) {
        vector<int> memo(n + 1 , 0);
        memo[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            int num = -1;
            int pos = 0;
            for(int j = 1 ; j < i ; j++){
                if(memo[i - j] * j > num){
                    num = memo[i - j] * (j);
                }
                if((i- j) * j > num) num = (i - j) *  j;
                }
            memo[i] = num;
        }
        return memo[n];
    }
};