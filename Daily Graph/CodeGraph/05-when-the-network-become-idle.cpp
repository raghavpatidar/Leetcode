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

Problem : https://leetcode.com/problems/the-time-when-the-network-becomes-idle/description/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<int> dist(n), adj[n], vis(n, 0);
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        vis[0] = 1;
        while (q.size() > 0) {
            int curr = q.front();
            q.pop();
            for (auto i : adj[curr]) {
                if (vis[i] == 0) {
                    vis[i] = 1;
                    dist[i] = 1 + dist[curr];
                    q.push(i);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int d = dist[i];
            int temp = 2 * d;
            //case when out period is smaller than total distance
            if (2 * d > patience[i])
            {
                // is last msg is sending condition but we revive
                if ((2 * d) % patience[i] == 0)
                    temp = 4 * d - patience[i];
                else
                    // we already send last msg
                    temp = 4 * d - (2 * d) % patience[i];
            }
            ans = max(ans, temp);
        }
        return ans + 1;
    }
};