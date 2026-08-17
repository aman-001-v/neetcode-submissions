class Solution {
public:
    bool passfunc(vector<int>& piles , int i , int j , vector<vector<int>>& dp , int curr , int turn){
        if(i > j){
            if(curr > 0) return true;
            else return false;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(turn == 0){
            bool a = passfunc(piles , i + 1 , j , dp , curr + piles[i] , 1);
            bool b = passfunc(piles , i , j -1 , dp , curr + piles[j] , 1);
            dp[i][j] = a && b;
        }else{
            bool a = passfunc(piles , i + 1 , j , dp , curr - piles[i] , 0);
            bool b = passfunc(piles , i , j -1 , dp , curr - piles[j] , 0);
            dp[i][j] = a || b;            
        }
        return dp[i][j];
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size() , vector<int>(piles.size() , -1));
        return passfunc(piles , 0 , 0 , dp , 0 , 0);
    }
};