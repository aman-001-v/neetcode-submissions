class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map <int , vector<int>> memo;
        vector<bool> visited(n , false);
        queue<int> connected;

        for(int i = 0 ; i < edges.size() ; i++){
            memo[edges[i][0]].push_back(edges[i][1]);
            memo[edges[i][1]].push_back(edges[i][0]);
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                count++;
                visited[i] = true;
                for(int j = 0 ; j < memo[i].size() ; j++){
                    connected.push(memo[i][j]);
                }
                
            }
            
            while(!connected.empty()){
                
                int t = connected.front();
                connected.pop();
                if(!visited[t]){
                    visited[t] = true;
                    for(int j = 0 ; j < memo[t].size() ; j++){
                        if(!visited[memo[t][j]]) connected.push(memo[t][j]);
                    }
                }
            }
        }
        return count;
    }
};
