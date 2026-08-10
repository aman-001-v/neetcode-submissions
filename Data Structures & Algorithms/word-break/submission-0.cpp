class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> memo(s.length() + 1 , false);
        memo[0] = true;

        for(int i = 1 ; i <= s.length() ; i++){
            for(const string& w: wordDict){
                int start = i - w.length();
                if(start >= 0 && memo[start] && s.substr(start , w.length()) == w){
                    memo[i] = true;
                    break;
                }
            }
        }
        return memo[s.length()];
    }
};