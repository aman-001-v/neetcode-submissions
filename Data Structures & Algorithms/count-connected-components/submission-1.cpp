class Solution {
public:
    void dfs(int num , unordered_map <int , vector<int>>& memo , vector<bool>& visited){
        if(visited[num]) return;

        visited[num] = true;

        for(int i = 0 ; i < memo[num].size() ; i++){
            if(!visited[memo[num][i]]) dfs(memo[num][i] , memo , visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map <int , vector<int>> memo;
        vector<bool> visited(n , false);

        for(int i = 0 ; i < edges.size() ; i++){
            memo[edges[i][0]].push_back(edges[i][1]);
            memo[edges[i][1]].push_back(edges[i][0]);
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                count++;
                dfs(i , memo , visited);
            }
        }
        return count;
    }
};
