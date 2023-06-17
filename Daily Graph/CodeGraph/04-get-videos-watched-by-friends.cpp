/*
┌────────────────────────────────────────────────────────────────────────────────────────┐
│                      *-----------Raghav Patidar----------*                             |
|                   Fuck Ratings,Just Enjoy the Contest/Questions                        |
|                      I'm in Love with Experience and Learning.                         |
│                                                                                        |
|    Leetcode   : https://leetcode.com/manito7/                                          |
|    CodingNinja: https://bit.ly/3IW2Nqi                                                 |
│    Github     : https://github.com/raghavpatidar                                       |
|    LinkedIn   : https://www.linkedin.com/in/raghavpatidar07/                           |
|    Resume     : https://drive.google.com/file/d/1nsTqWKSzxl-tcIXARi_b6vMSVcz57cVQ/view |
|    Codeforces : https://codeforces.com/profile/raghavpatidar                           |
|                                                                                        |
└────────────────────────────────────────────────────────────────────────────────────────┘

Problem : https://leetcode.com/problems/get-watched-videos-by-your-friends/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


// Note :in BFs always mark visit child when pushing into queye not when taking out from queue
// This will not give tle but it will add child many times and time complexity will be increase and may give TLE
// i have stress test on one of testcase where 
// in first i am getting only 13 nodes at level x with marking visit at pushing into queue
// second i am getting 1352 nodes at level x with marking when popping out from queue (duplication of nodes if we reomove duplication)
// then we will get the same 13 nodes



class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& adj, int id, int level) {
        int d = 0;
        int n = adj.size();
        queue<int> q;
        q.push(id);
        vector<int> vis(n, 0);
        vector<string> ans;
        map<string, int>freq;
        map<int, vector<string>> mp;
        while (q.size() > 0) {
            int sz = q.size();
            for (int i = 0;i < sz;i++) {
                int curr = q.front();
                q.pop();
                vis[curr] = 1;
                // find given level update frequency of videos of given friend 
                if (d == level)for (auto j : watchedVideos[curr])freq[j]++;

                for (int child : adj[curr]) {
                    if (!vis[child]) {
                        vis[child] = 1;
                        q.push(child);
                    }
                }
            }
            if (d == level)break;
            d++;
        }
        for (auto [st, f] : freq)mp[f].push_back(st);
        for (auto [f, v] : mp) {
            for (auto i : v)ans.push_back(i);
        }
        return ans;


    }
};









