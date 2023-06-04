/*
┌────────────────────────────────────────────────────────────────────────────────────────┐
│                      *-----------Raghav Patidar----------*                             |
|                   Fuck Ratings,Just Enjoy the Contest/Questions                        |
|                      I'm in Love with Experience and Learning.                         |
│                                                                                        |
|    Leetcode   : https://leetcode.com/manito7/                                          |
│    Github     : https://github.com/raghavpatidar                                       |
|    LinkedIn   : https://www.linkedin.com/in/raghavpatidar07/                           |
|    Resume     : https://drive.google.com/file/d/1nsTqWKSzxl-tcIXARi_b6vMSVcz57cVQ/view |
|    Codeforces : https://codeforces.com/profile/raghavpatidar                           |
|                                                                                        |
└────────────────────────────────────────────────────────────────────────────────────────┘

Problem : https://leetcode.com/problems/number-of-provinces/description/
Day : 393
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vis[205];
    vector<int> adj[205];
    void dfs(int node) {
        vis[node] = 1;
        for (auto i : adj[node]) {
            if (vis[i] == 0)dfs(i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n;j++) {
                if (i != j and isConnected[i][j] == 1)adj[i].push_back(j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                ans++;
                dfs(i);
            }
        }
        return ans;

    }
};