class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        vector<pair<int , int>> memo;
        int n = profits.size();

        for(int i = 0 ; i < n ; i++){
            memo.push_back({capital[i] , profits[i]});
        }
        sort(memo.begin(),memo.end());
        priority_queue<int> que;
        int count = 0;
        int i = 0;
        while(i < n && w >= memo[i].first){
            que.push(memo[i].second);
            i++;
        }

        while(count < k){
            while(i < n && w >= memo[i].first){
                que.push(memo[i].second);
                i++;
            }
            if(que.empty()) return w;
            w += que.top();
            que.pop();
            count++;
        }

        return w;
    }
};