class Solution {
public:
    void passfunc(vector<vector<char>>& grid , int i , int j){
        if(grid[i][j] != '1') return;
        grid[i][j] = '2';
        if(j < grid[0].size() - 1) passfunc(grid , i , j + 1);
        if(i < grid.size() - 1) passfunc(grid , i + 1 , j);
        if(i > 0) passfunc(grid , i - 1 , j);
        if(j > 0) passfunc(grid , i , j - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int i = 0; i< grid.size() ; i++){
            for(int j =0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == '1'){
                    result++;
                    passfunc(grid , i , j);
                } 
            }
        }
        return result;
    }
};