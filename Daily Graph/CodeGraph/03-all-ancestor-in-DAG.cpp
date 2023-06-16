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

Problem : https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void addAncestor(int node, int ancestor, vector<set<int>>& ans) {
        for (auto i : ans[ancestor]) {
            ans[node].insert(i);
        }
        ans[node].insert(ancestor);
    }
    void dfs(int node, vector<int> adj[], vector<set<int>>& ans, vector<int>& vis) {
        vis[node] = 1;

        for (auto child : adj[node]) {
            if (vis[child] == 0) {
                dfs(child, adj, ans, vis);
                //go do dfs then add result to our answer list
            }
            addAncestor(node, child, ans);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n], vis(n, 0), in(n, 0);
        for (auto i : edges) {
            int u = i[0], v = i[1];
            adj[v].push_back(u);
            in[u]++;
        }
        vector<set<int>> ans(n);
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                dfs(i, adj, ans, vis);
            }
        }
        for (int i = 0; i < n; i++) {
            for (auto j : ans[i]) {
                v[i].push_back(j);
            }
        }
        return v;
    }
};