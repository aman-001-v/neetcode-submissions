class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        sort(edges.begin(), edges.end());
        unordered_set <int> memo;
        for(int i = 0 ; i < n - 1 ; i++){
            if(memo.contains(edges[i][0])){
                if(memo.contains(edges[i][1])) return false;
                else memo.insert(edges[i][1]);
            }
            else{
                memo.insert(edges[i][0]);
                memo.insert(edges[i][1]);
            }
        }
        
        return true;
    }
};
