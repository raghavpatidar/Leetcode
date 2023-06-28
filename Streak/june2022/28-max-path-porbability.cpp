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

Problem : https://leetcode.com/problems/path-with-maximum-probability/submissions/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];
        int k = 0;
        for (auto i : edges) {
            int u = i[0], v = i[1];
            double w = succProb[k++];
            adj[u].push_back({ v , w });
            adj[v].push_back({ u , w });
        }
        priority_queue< pair<int, double>, vector<pair<int, double>>, greater<pair<int, double>> > pq;
        pq.push({ start , 1.0 });
        vector<double> dist(n, 0.0);
        while (pq.size() > 0) {
            int curr = pq.top().first;
            double d = pq.top().second;
            pq.pop();

            for (auto i : adj[curr]) {
                double childDist = d * i.second;
                int child = i.first;

                if (childDist > dist[child]) {
                    dist[child] = childDist;
                    pq.push({ child , dist[child] });
                }
            }
        }
        return dist[end];
    }
};