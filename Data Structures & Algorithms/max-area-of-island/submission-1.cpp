class Solution {
public:
    void passfunc(vector<vector<int>>& grid , int i , int j , int& area){
        if(grid[i][j] != 1) return;
        area++;
        grid[i][j] = 2;
        if(i < grid.size() - 1) passfunc(grid , i + 1 , j , area);
        if(i > 0) passfunc(grid , i - 1 , j , area);
        if(j < grid[0].size() - 1) passfunc(grid , i , j + 1 , area);
        if(j > 0) passfunc(grid , i , j - 1 , area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    passfunc(grid , i , j , area);
                    max_area = max(max_area , area);
                }
            }
        }
        return max_area;
    }
};