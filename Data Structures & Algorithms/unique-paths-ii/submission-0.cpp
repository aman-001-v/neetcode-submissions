class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(obstacleGrid[i][j] == 1) obstacleGrid[i][j] = -1;
            }
        }

        obstacleGrid[0][0] = 1;
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n ; j++){
                if(obstacleGrid[i][j] == -1) continue;
                int curr = 0;
                if(i > 0 && obstacleGrid[i - 1][j] != -1) curr += obstacleGrid[i - 1][j];
                if(j > 0 && obstacleGrid[i][j - 1] != -1) curr += obstacleGrid[i][j - 1];

                obstacleGrid[i][j] += curr;
            }
        }
        return max( 0 , obstacleGrid[m - 1][n -1]);
    }
};