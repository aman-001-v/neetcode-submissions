class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i = 0 ; i < tasks.size() ; i++){
            tasks[i].push_back(i);
        }
        stable_sort(tasks.begin(), tasks.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int i = 0;
        long long time = tasks[i][0];
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>> > memo;
        while(i < tasks.size() && tasks[i][0] <= time){
            memo.push({tasks[i][1] , tasks[i][2]});
            i++;
        }
        vector<int> res;
        while(!memo.empty()){
            int t = memo.top().first;
            res.push_back(memo.top().second);
            memo.pop();
            time += t;
            while(i < tasks.size() && tasks[i][0] <= time){
                memo.push({tasks[i][1] , tasks[i][2]});
                i++;
            }
            if(memo.empty() && i != tasks.size()){
                time = tasks[i][0];
                while(i < tasks.size() && tasks[i][0] <= time){
                memo.push({tasks[i][1] , tasks[i][2]});
                i++;
            }
            }
        }
        return res;
    }
};