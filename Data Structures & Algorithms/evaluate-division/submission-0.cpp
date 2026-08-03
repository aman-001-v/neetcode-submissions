class Solution {
public:
    double bfs(unordered_map<string , unordered_map<string , double>>& memo , string src , string target){
        if(!memo.contains(src) || !memo.contains(target)) return -1;
        queue<pair<string , double>> que;
        unordered_set<string> visited;
        que.push({src , 1.0});
        visited.insert(src);
        while(!que.empty()){
            int n = que.size();
            for(int i = 0 ; i < n ; i++){
                string temp = que.front().first;
                double val = que.front().second;
                que.pop();
                if(temp == target) return val;
                for(const auto& q: memo[temp]){
                    if(!visited.contains(q.first)){
                        que.push({q.first , val * memo[temp][q.first]});
                        visited.insert(q.first);
                    }
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string , unordered_map<string , double>> memo;
        vector<double> result;
        for(int i = 0 ; i < equations.size() ; i++){
            memo[equations[i][0]][equations[i][1]] = values[i];
            memo[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        for(int i = 0 ; i < queries.size() ; i++){
            result.push_back(bfs(memo , queries[i][0] , queries[i][1]));
        }
        return result;
    }
};