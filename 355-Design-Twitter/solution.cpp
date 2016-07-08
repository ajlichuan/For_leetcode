class Twitter {
private:
    vector<int> mes; // queque of the message in order of time <id>
    unordered_map<int,vector<int>> usr_post;
    unordered_map<int,vector<int>> usr_flw;
    int cnt;
public:
    /** Initialize your data structure here. */
    Twitter() {
        cnt = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        mes.push_back(tweetId);
        usr_post[userId].push_back(cnt++);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> tmp(usr_post[userId]);
        vector<int> &flw = usr_flw[userId];
        vector<int> res;

        int len = flw.size();
        for(int i = 0; i < len; i++)
        {
            tmp.insert(tmp.end(),usr_post[flw[i]].begin(),usr_post[flw[i]].end());
        }
        sort(tmp.begin(),tmp.end());
        
        len = tmp.size();
        for(int i = len-1; i >= max(0,len-10); i--)
        {
            res.push_back(mes[tmp[i]]);
        }
        
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
        {
            vector<int> &flw = usr_flw[followerId];
            int len = flw.size();
            for(int i = 0; i < len; i++)
            {
                if(flw[i] == followeeId)
                    return;
            }
            flw.push_back(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        vector<int> &tmp = usr_flw[followerId];
        for(auto it = tmp.begin(); it != tmp.end(); ++it)
        {
            if(*it == followeeId)
            {
                tmp.erase(it);
                break;
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */