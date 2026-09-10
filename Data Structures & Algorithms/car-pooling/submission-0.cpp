class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int car = 0;
        stable_sort(trips.begin(), trips.end(),
    [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
    });

    int i = 0;
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> que;
    for(int i = 0 ; i < trips.size() ; i++){
        if(!que.empty()){
            while(!que.empty() && que.top().first <= trips[i][1]){
                car -= trips[que.top().second][0];
                que.pop();
            }
        }
        car += trips[i][0];
        if(car > capacity) return false;
        que.push({trips[i][2] , i});
    }
    return true;
    }
};