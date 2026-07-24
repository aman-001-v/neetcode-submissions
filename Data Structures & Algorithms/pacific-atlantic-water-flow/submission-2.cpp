class Solution {
public:
    void dfs(vector<vector<int>>& heights , int i , int j , vector<vector<bool>>& pacific , vector<vector<bool>>& p_visited){

        pacific[i][j] = true;
        p_visited[i][j] = true;

        if(i > 0 && heights[i][j] <= heights[i - 1][j] && !p_visited[i - 1][j]) dfs(heights , i - 1 , j , pacific , p_visited);
        
        if(i < heights.size() - 1 && heights[i][j] <= heights[i + 1][j] && !p_visited[i + 1][j]) dfs(heights , i + 1 , j , pacific , p_visited);

        if(j > 0 && heights[i][j] <= heights[i][j - 1] && !p_visited[i][j - 1]) dfs(heights , i , j - 1 , pacific , p_visited);

        if(j < heights[0].size() - 1 && heights[i][j] <= heights[i][j + 1] && !p_visited[i][j + 1]) dfs(heights , i, j  + 1 , pacific , p_visited);

    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific(heights.size() , vector<bool>(heights[0].size() , false));
        vector<vector<bool>> atlantic(heights.size() , vector<bool>(heights[0].size() , false));
        vector<vector<bool>> p_visited(heights.size() , vector<bool>(heights[0].size() , false));
        vector<vector<bool>> a_visited(heights.size() , vector<bool>(heights[0].size() , false));

        for(int i = 0 ; i < heights[0].size() ; i++){
            dfs(heights , 0 , i , pacific , p_visited);
        }
        for(int i = 0 ; i < heights.size() ; i++){
            dfs(heights , i , 0 , pacific , p_visited);
        }

        for(int i = 0 ; i < heights[0].size() ; i++){
            dfs(heights , heights.size() - 1 , i , atlantic , a_visited);
        }
        for(int i = 0 ; i < heights.size() ; i++){
            dfs(heights , i , heights[0].size() - 1 , atlantic , a_visited);
        }

        vector<vector<int>> result;
        for(int i = 0 ; i < heights.size() ; i++){
            for(int j = 0 ; j < heights[0].size() ; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i , j});
                }
            }
        }
        return result;
    }
};