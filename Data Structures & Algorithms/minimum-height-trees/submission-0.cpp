class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<unordered_set<int>> memo(n);

        for(const auto& e: edges){
            memo[e[0]].insert(e[1]);
            memo[e[1]].insert(e[0]);
        }

        queue<int> leaves;
        for(int i = 0; i < n ; i++){
            if(memo[i].size() == 1) leaves.push(i);
        }

        int remaining = n;

        while(remaining > 2){
            int s = leaves.size();
            remaining -= s;

            for(int i = 0 ; i < s ; i++){
                int temp = leaves.front();
                leaves.pop();

                for(int q: memo[temp]){
                    memo[q].erase(temp);
                    if(memo[q].size() == 1) leaves.push(q);
                }
            }
        }
        vector<int> result;
        while(!leaves.empty()){
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};