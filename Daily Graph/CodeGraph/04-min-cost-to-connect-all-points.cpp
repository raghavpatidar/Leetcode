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

Problem : https://leetcode.com/problems/min-cost-to-connect-all-points/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


#define pll pair<int,int>
class Solution {
public:
    int parent[1005];
    int find(int n) {
        if (parent[n] == n)return n;
        return parent[n] = find(parent[n]);
    }
    void unite(int a, int b) {
        int parA = find(a);
        int parB = find(b);
        parent[parA] = parB;
    }
    int krushkals(vector<vector<int>>& points) {
        for (int i = 0; i < points.size();i++)parent[i] = i;
        vector<pair<int, pair<int, int>>> adj;

        int n = points.size();
        // generating graph basically with weights
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int weight = abs(points[i][0] - points[j][0]) +
                    abs(points[i][1] - points[j][1]);//manhattan distance

                adj.push_back({ weight, {i, j} });

            }
        }

        // sort on the basis of their edge weight
        sort(adj.begin(), adj.end());
        int sum = 0;
        for (int i = 0; i < adj.size();i++) {
            int a = adj[i].second.first;
            int b = adj[i].second.second;
            if (find(a) != find(b)) {
                unite(a, b);
                sum += adj[i].first;
            }
        }
        return sum;
    }

    int prims(vector<vector<int>>& points) {
        priority_queue<pll, vector<pll>, greater<pll> >pq;
        pq.push({ 0 , 0 });
        int sum = 0;
        vector<int> vis(points.size(), 0);
        while (pq.size() > 0) {
            int wt = pq.top().first;
            int idx = pq.top().second;
            int currX = points[idx][0];
            int currY = points[idx][1];
            pq.pop();
            if (vis[idx] == 1)continue;


            vis[idx] = 1;
            sum += wt;

            for (int i = 0; i < points.size();i++) {
                int childX = points[i][0];
                int childY = points[i][1];
                int childWt = abs(childX - currX) + abs(childY - currY);
                if (vis[i] == 0) {
                    pq.push({ childWt , i });
                }
            }

        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        // return prims(points);
        return krushkals(points);

    }
};