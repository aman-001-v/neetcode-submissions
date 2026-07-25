class Solution {
public:
    bool dfs(vector<vector<int>>& memo , unordered_set<int>& acquired , unordered_set<int>& waiting , int num , vector<int>& result){
        if(acquired.contains(num)) return true;
        if(memo[num].empty()) return true;
        waiting.insert(num);
        bool flag = true;
        for(int i = 0 ; i < memo[num].size() ; i++){
            if(waiting.contains(memo[num][i])) return false;
            flag = dfs(memo , acquired , waiting , memo[num][i] , result);
            if(!flag) return false;
            if(!acquired.contains(memo[num][i])) {
                result.push_back(memo[num][i]);
                acquired.insert(memo[num][i]);
            }
            
        }
        waiting.erase(num);
        return true;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> memo(numCourses);
        for(int i = 0 ; i< prerequisites.size(); i++){
            memo[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_set<int> acquired;
        unordered_set<int> waiting;
        vector<int> result;
        bool flag = true;
        for(int i = 0 ; i < numCourses ; i++){
            if(acquired.contains(i)) continue;
            flag = dfs(memo , acquired , waiting , i , result);
            if(!flag) return {};
            if(!acquired.contains(i)){
                result.push_back(i);
                acquired.insert(i);
            }
            
        }
        return result;
    }
};