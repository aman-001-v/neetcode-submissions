class Solution {
public:
    bool dfs_pacific(vector<vector<int>>& heights , int i , int j , vector<vector<vector<bool>>>& memo){

        if(memo[i][j][0]){
            return memo[i][j][1];
        }
        if(i == 0){
            memo[i][j][1] = true;
            memo[i][j][0] = true;
            return true;
        }
        if(j == 0){
            memo[i][j][1] = true;
            memo[i][j][0] = true;
            return true;
        }
        memo[i][j][0] = true;
        bool left = false , right = false , up = false , down = false;
        
        if(i > 0 && heights[i][j] >= heights[i - 1][j]) up = dfs_pacific(heights , i - 1 , j , memo);

        if(!up && j > 0 && heights[i][j] >= heights[i][j - 1]) left = dfs_pacific(heights , i , j - 1 , memo);

        if(!up && !left && i < heights.size() - 1 && heights[i][j] >= heights[i + 1][j]) down = dfs_pacific(heights , i + 1 , j , memo);

        if(!up && !left && !down && j < heights[0].size() - 1 && heights[i][j] >= heights[i][j + 1]) right = dfs_pacific(heights , i , j + 1 , memo);
        memo[i][j][1] = up || down || left || right;

        // if(!memo[i][j][1]) memo[i][j][0] = false;

        return memo[i][j][1];
    }

    bool dfs_atlantic(vector<vector<int>>& heights , int i , int j , vector<vector<vector<bool>>>& memo){
        
        if(memo[i][j][3]){
            return memo[i][j][2];
        }

        if(i == heights.size() - 1){
            memo[i][j][2] = true;
            memo[i][j][3] = true;
            return true;
        }
        if(j == heights[0].size() - 1){
            memo[i][j][2] = true;
            memo[i][j][3] = true;
            return true;
        }
        memo[i][j][3] = true;
        bool left = false , right = false , up = false , down = false;
        
        if(j < heights[0].size() - 1 && heights[i][j] >= heights[i][j + 1]) right = dfs_atlantic(heights , i , j + 1 , memo);

        if(!right && i < heights.size() - 1 && heights[i][j] >= heights[i + 1][j]) down = dfs_atlantic(heights , i + 1 , j , memo);

        if(!right && !down && j > 0 && heights[i][j] >= heights[i][j - 1]) left = dfs_atlantic(heights , i , j - 1 , memo);

        if(!right && !down && !left && i > 0 && heights[i][j] >= heights[i - 1][j]) up = dfs_atlantic(heights , i - 1 , j , memo);

        memo[i][j][2] = up || down || left || right;

        // if(!memo[i][j][2]) memo[i][j][3] = false;
        return memo[i][j][2];
    }

    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<vector<bool>>> memo(heights.size() , vector<vector<bool>>(heights[0].size() , vector<bool>(4 , false)));
        vector<vector<int>> result;
        
        for(int i = 0; i < heights.size() ; i++){
            for(int j = 0; j < heights[0].size() ; j++){

                if (!memo[i][j][0]){
                    // cout << i << j << endl;
                    dfs_pacific(heights , i , j , memo);
                    // memo[i][j][0] = true;
                }
                if(!memo[i][j][3]){
                    dfs_atlantic(heights , i , j , memo);
                    // memo[i][j][3] = true;
                }
                if(memo[i][j][1] && memo[i][j][2]){
                    result.push_back({i,j});
                }
            }
        }
        
        return result;
    }
};