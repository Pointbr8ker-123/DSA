#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

class Twitter {
private:
    // this would be used for 'latest 10' operations
    int k = 10;

    // initialize a timestamp 'count' that records when a particular
    // tweet was posted so as to accurately keep track of latest 10 tweets
    int count = 0;

    // create a hashmap that stores the account ids for the accounts the
    // user is following. It stores the account Ids in a hashset so we can
    // retrieve these users if needed in O(1) time complexity
    unordered_map<int, unordered_set<int>> followeeMap;

    // create another hashmap that stores each users tweetIds in a vector 
    // alongside the timestamp for when the tweet was posted; hence the need
    // for a vector of pairs
    unordered_map<int, vector<pi>> tweetMap;

public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count, tweetId});
        count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // this min heap helps us get the top 10 latest tweets by
        // sorting by the timestamp 'count' to figure which tweets
        // were posted first
        priority_queue<pi, vector<pi>, greater<pi>> minHeap;

        int n = tweetMap[userId].size();

        // for the current user: get the top 10 tweets
        // if the tweets arent up to 10, get them all
        for (int i = n - 1; i >= max(0, n-k); i--) {
            minHeap.push(tweetMap[userId][i]);
        }

        // go through each of the user's followees and get thier latests 
        // tweets till we have the top 10 latest tweets (by timestamp)
        // which the minheap helps use do
        for (int followee : followeeMap[userId]) {
            int n = tweetMap[followee].size();

            for (int i = n - 1; i >= max(0, n-k); i--) {
                minHeap.push(tweetMap[followee][i]);

                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
        }

        // we store the tweetIds for the top 10 latest tweets in a 
        // separate array as our answer
        vector<int> feed;
        while (!minHeap.empty()) {
            feed.push_back(minHeap.top().second);
            minHeap.pop();
        }

        // since we're retrieving the values from a minheap,
        // we'd be getting the array in the order from least recent by 10
        // to most recent tweetID). But the answer is expected as a list 
        // of tweetIDs from most recent tweetID -> least recent by 10, so
        // we have to reverse the list before returning it
        reverse(feed.begin(), feed.end());
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followeeMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followeeMap[followerId].erase(followeeId);
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