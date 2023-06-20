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

Problem : https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> dikjstras(int n, vector<pair<int, int>> adj[]) {
        vector<int> dist(n + 2, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0 , n });
        dist[n] = 0;
        while (pq.size() > 0) {
            auto [d, curr] = pq.top();
            pq.pop();
            for (auto [child, wt] : adj[curr]) {
                if (wt + d < dist[child]) {
                    dist[child] = wt + d;
                    pq.push({ dist[child] , child });
                }
            }
        }
        return dist;
    }
    void dfs(int node, int  n, int mod, vector<pair<int, int>>adj[], vector<int>& dist, vector<int>& dp, vector<int>& vis) {
        vis[node] = 1;
        if (n == node)return;
        dp[node] = 0;
        for (auto [child, wt] : adj[node]) {
            if (vis[child] == 0) {
                if (dist[child] < dist[node]) {
                    dfs(child, n, mod, adj, dist, dp, vis);
                    dp[node] = (dp[node] % mod + dp[child] % mod) % mod;
                }
            }
            else {
                if (dist[child] < dist[node]) {
                    dp[node] = (dp[node] % mod + dp[child] % mod) % mod;
                }
            }
        }
        dp[node] = dp[node] % mod;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n + 1];
        for (auto i : edges) {
            adj[i[0]].push_back({ i[1] , i[2] });
            adj[i[1]].push_back({ i[0] , i[2] });
        }
        vector<int> vis(n + 1, 0), dp(n + 1, 0), dist = dikjstras(n, adj);
        dp[n] = 1;
        int mod = 1e9 + 7;
        dfs(1, n, mod, adj, dist, dp, vis);
        return dp[1];
    }

};