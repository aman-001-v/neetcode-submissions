class Solution {
public:
    void dfs(int num , unordered_map<int , unordered_set<int>>& memo , vector<bool>& visited){
        if(visited[num]) return;
        visited[num] = true;
        if(!memo.contains(num)) return;

        for(auto q : memo[num]){
            if(memo.contains(q)){
                if(!visited[q]) dfs(q , memo , visited);
                for(auto m : memo[q]){
                    memo[num].insert(m);
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int , unordered_set<int>> memo;
        vector<bool> visited(numCourses , false);
        for(int i = 0 ; i < prerequisites.size() ; i++){
            memo[prerequisites[i][1]].insert(prerequisites[i][0]);
        }
        
        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i]) dfs(i , memo , visited);
        }
        vector<bool> result;
        for(auto q : queries){
            if(memo[q[1]].contains(q[0])) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};