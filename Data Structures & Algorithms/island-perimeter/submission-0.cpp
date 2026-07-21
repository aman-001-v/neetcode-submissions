class Solution {
public:
    void passfunc(vector<vector<int>>& grid , int row , int column , int& parameter){
        if(grid[row][column] != 1) return;

        grid[row][column] = 2;

        int count = 0;

        if(row == 0)count++;
        else if(row > 0){
            if(grid[row - 1][column] == 1) passfunc(grid , row - 1 , column , parameter);
            else if(grid[row - 1][column] == 0 ) count++;
        } 

        if(row == grid.size() - 1) count++;
        else if(row < grid.size() - 1){
            if(grid[row + 1][column] == 0) count++;
            else if(grid[row + 1][column] == 1) passfunc(grid , row + 1 , column , parameter);
        }
        if(column == grid[0].size() - 1) count++;
        else if(column < grid[0].size() - 1){
            if(grid[row][column + 1] == 0) count++;
            else if(grid[row][column + 1] == 1) passfunc(grid , row , column + 1 , parameter);
        }

        if(column == 0)count++;
        else if(column > 0){
            
            if(grid[row][column - 1] == 1) passfunc(grid , row , column - 1, parameter);
            else if(grid[row][column - 1] == 0 ) count++;
        } 

        parameter += count;
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int parameter = 0;
        for(int i = 0; i < grid.size() ; i++){
            for(int j = 0; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    passfunc(grid , i , j , parameter);
                    return parameter;
                }
            }
        }
        return parameter;
    }
};