class Twitter {
    unordered_map<int, unordered_set<int>> followMap; // userId -> set of followeeIds
    unordered_map<int, vector<pair<int, int>>> tweetMap; // userId -> [(time, tweetId)]
    int time = 0;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({++time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        // Max-heap: (timestamp, followeeId, index into that user's tweet list)
        priority_queue<tuple<int,int,int>> maxHeap;
        
        // Add self
        if(!tweetMap[userId].empty()){
            int idx = tweetMap[userId].size() - 1;
            maxHeap.push({tweetMap[userId][idx].first, userId, idx});
        }

        // Add all followees
        for(int followee:followMap[userId]){
            if(!tweetMap[followee].empty()){
                int idx = tweetMap[followee].size() - 1;
                maxHeap.push({tweetMap[followee][idx].first, followee, idx});
            }
        }

        vector<int> newsFeeds;

        while(!maxHeap.empty() && newsFeeds.size() < 10){
            auto [t, uid, idx] = maxHeap.top();
            maxHeap.pop();

            newsFeeds.push_back(tweetMap[uid][idx].second);

            // Push next older tweet from same user
            if(idx > 0){
                maxHeap.push({tweetMap[uid][idx-1].first, uid, idx-1});
            }
        }

        return newsFeeds;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followMap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
