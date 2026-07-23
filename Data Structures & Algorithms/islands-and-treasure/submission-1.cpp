class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> memo;

        for(int i = 0 ; i< grid.size() ; i++){
            for(int j = 0; j < grid[0].size() ; j++){
                if(grid[i][j] == 0) memo.push({i,j});
            }
        }
        int count = memo.size();
        while(!memo.empty()){
            for(int k = 0 ; k < count ; k++){
                int i = memo.front().first;
                int j = memo.front().second;
                memo.pop();
                if(i > 0 && grid[i - 1][j] != -1 && grid[i - 1][j] > 1 + grid[i][j]){
                    
                    grid[i - 1][j] = 1 + grid[i][j];
                    memo.push({i - 1 , j});
                }
                if(i < grid.size() - 1 && grid[i + 1][j] != -1 && grid[i + 1][j] >  1 + grid[i][j]){
                    grid[i + 1][j] = 1 + grid[i][j];
                    memo.push({i + 1 , j});
                }
                if(j > 0 && grid[i][j - 1] != -1 && grid[i][j - 1] > grid[i][j]){
                    grid[i][j - 1] = 1 + grid[i][j];
                    memo.push({i , j - 1});
                }
                if(j < grid[0].size() - 1 && grid[i][j + 1] != -1 && grid[i][j + 1] > grid[i][j]){
                    grid[i][j + 1] = 1 + grid[i][j];
                    memo.push({i , j + 1});
                }
            }
            count = memo.size();
        }
    }
};
