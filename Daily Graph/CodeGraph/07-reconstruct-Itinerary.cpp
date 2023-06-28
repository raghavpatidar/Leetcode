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

Problem : https://leetcode.com/problems/reconstruct-itinerary/
Day :
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node, vector<int> adj[], vector<int>& path, map<pair<int, int>, int >& mp, vector<int>out) {
        for (auto i : adj[node]) {
            if (mp.find({ node , i }) != mp.end() and mp[{node, i}] > 0) {
                mp[{node, i }]--;
                out[i]--;
                dfs(i, adj, path, mp, out);
            }
        }
        path.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, int> hash;
        map<int, string> reverseHash;
        int id = 1;
        hash["JFK"] = 0;
        reverseHash[0] = "JFK";
        for (auto i : tickets) {
            if (hash.find(i[0]) == hash.end()) {
                hash[i[0]] = id;
                reverseHash[id] = i[0];
                id++;
            }
            if (hash.find(i[1]) == hash.end()) {
                hash[i[1]] = id;
                reverseHash[id] = i[1];
                id++;
            }
        }
        int n = hash.size();
        vector<int>out(n, 0);
        vector<int> adj[n];
        map<pair<int, int>, int  > mp;
        for (auto i : tickets) {
            int u = hash[i[0]];
            int v = hash[i[1]];
            adj[u].push_back(v);
            out[u]++;
            mp[{u, v}]++;
        }
        for (int i = 0; i < n; i++) {
            sort(adj[i].begin(), adj[i].end(), [&](const int& a, const int& b) {  return reverseHash[a] < reverseHash[b];});
        }

        vector<int> path, vis(n, 0);
        vector<string> ans;
        dfs(0, adj, path, mp, out);
        for (auto i : path) {
            ans.push_back(reverseHash[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};