class Solution {
public:
    bool dfs(vector<vector<int>>& memo , unordered_set<int>& acquired , unordered_set<int>& waiting , int num){
        if(acquired.contains(num)) return true;
        if(memo[num].empty()) return true;
        waiting.insert(num);
        bool flag = true;
        for(int i = 0 ; i < memo[num].size() ; i++){
            if(waiting.contains(memo[num][i])) return false;
            flag = dfs(memo , acquired , waiting , memo[num][i]);
            if(!flag) return false;
            acquired.insert(memo[num][i]);
        }
        waiting.erase(num);
        return true;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> memo(numCourses);
        for(int i = 0 ; i< prerequisites.size(); i++){
            memo[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_set<int> acquired;
        unordered_set<int> waiting;
        bool flag = true;
        for(int i = 0 ; i < numCourses ; i++){
            if(acquired.contains(i)) continue;
            flag = dfs(memo , acquired , waiting , i);
            if(!flag) return false;
            acquired.insert(i);
        }
        return true;
    }
};