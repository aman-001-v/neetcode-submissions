class Twitter {
public:
    unordered_map<int , unordered_set<int>> friendlist;
    vector<pair<int,int>> memo;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        memo.push_back({tweetId , userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        int i = memo.size() - 1;
        while(res.size() < 10 && i >= 0){
            if(memo[i].second == userId){
                res.push_back(memo[i].first);
            }
            else if(friendlist[userId].contains(memo[i].second)){
                res.push_back(memo[i].first);
            }
            i--;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        friendlist[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friendlist[followerId].erase(followeeId);
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