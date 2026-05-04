class Twitter {
public:
    unordered_map<int, unordered_set<int>>followerMap;
    unordered_map<int, vector<pair<int,int>>>tweetsMap;
    int count;
    Twitter() {
        count = 0;
    }
    

    void postTweet(int userId, int tweetId) {
        tweetsMap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int>followers = followerMap[userId];
        followers.insert(userId);
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i: followers) {
            if(tweetsMap[i].size() >= 1) {
                 auto lastTweetByFollower = tweetsMap[i].back();
            pq.push({lastTweetByFollower.first, { i, tweetsMap[i].size()-1}});
        
            }
        }

        vector<int>res;
        while(!pq.empty()) {
            auto lastTweet = pq.top();
            int user = lastTweet.second.first;
            int tweetIndex = lastTweet.second.second;
            res.push_back(tweetsMap[user][tweetIndex].second);
            if(res.size()==10)  break;
            pq.pop();
            if(tweetIndex > 0) {
                --tweetIndex;
                auto nextTweetByFollower = tweetsMap[user][tweetIndex];
                pq.push({nextTweetByFollower.first, {user, tweetIndex}});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerMap[followerId].erase(followeeId);
    }
};
