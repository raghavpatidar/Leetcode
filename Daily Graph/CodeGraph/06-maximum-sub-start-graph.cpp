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

Problem : https://leetcode.com/problems/maximum-star-sum-of-a-graph/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<int> adj[n];
        for (auto i : edges) {
            int u = i[0], v = i[1];
            adj[u].push_back(vals[v]);
            adj[v].push_back(vals[u]);
        }
        int ans = -1e9;
        for (int i = 0; i < n; i++) {
            sort(adj[i].begin(), adj[i].end(), greater<int>());
            int ctr = vals[i];
            int sz = adj[i].size();
            for (int j = 0; j < min(sz, k); j++) {
                ans = max(ans, ctr);
                int node = adj[i][j];
                ctr += node;
            }
            ans = max(ans, ctr);
        }
        return ans;
    }
};