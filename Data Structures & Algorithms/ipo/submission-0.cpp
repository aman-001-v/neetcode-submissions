class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> que1;
        int n = profits.size();

        for(int i = 0 ; i < n ; i++){
            que1.push({capital[i] , profits[i]});
        }

        priority_queue<int> que;
        int count = 0;

        while(!que1.empty() && w >= que1.top().first){
            que.push(que1.top().second);
            que1.pop();
        }

        while(count < k){
            while(!que1.empty() && w >= que1.top().first){
                que.push(que1.top().second);
                que1.pop();
            }
            if(que.empty()) return w;
            w += que.top();
            que.pop();
            count++;
        }

        return w;
    }
};