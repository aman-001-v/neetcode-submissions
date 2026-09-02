class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<unsigned int> memo(m + 1 , 0);
        vector<unsigned int> prev(m + 1 , 0);

        memo[0] = 1;
        prev[0] = 1;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){

                if(s[i - 1] == t[j - 1]){
                    memo[j] += prev[j - 1];
                }
                

            }
            prev = memo;
        }
        return memo[m];
    }
};
