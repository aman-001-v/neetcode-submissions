class Twitter {
public:
    unordered_map<int , unordered_set<int>> friendlist;
    unordered_map<int , vector<pair<int , int>>> memo;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        memo[userId].push_back({time , tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int , int>> maxheap;
        for(auto& q: memo[userId]){
            maxheap.push(q);
        }
        for(auto& id: friendlist[userId]){
            for(auto& q: memo[id]){
                maxheap.push(q);
            }
        }
        while(!maxheap.empty() && res.size() < 10){
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }
        time++;
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        friendlist[followerId].insert(followeeId);
        time++;
    }
    
    void unfollow(int followerId, int followeeId) {
        friendlist[followerId].erase(followeeId);
        time++;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */