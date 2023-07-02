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

Problem : https://leetcode.com/problems/shortest-path-in-binary-matrix/submissions/961741983/
Day : 390
*/

#include<bits/stdc++.h>
using namespace std;


#define pll pair<int,int>
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1)return -1;
        // queue<pair<int , pair<int,int>>> q;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> vis(n, vector<int>(m, 1e9));
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        // {dist , {x , y}}
        int dx[8] = { 0 , -1 , 0 ,  1  , -1 , 1 , -1 , 1 };
        int dy[8] = { 1 , 0 , -1 , 0 ,   -1 , 1 , 1  , -1 };
        if (grid[0][0] == 0)dist[0][0] = 1;
        pq.push({ dist[0][0] , {0 , 0} });

        while (pq.size() > 0) {
            int currd = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 and ny >= 0 and nx < n and ny < m and grid[nx][ny] == 0) {
                    if (dist[nx][ny] > 1 + currd) {
                        dist[nx][ny] = 1 + currd;
                        pq.push({ dist[nx][ny] , {nx , ny} });
                    }
                }
            }
        }
        return dist[n - 1][m - 1] == 1e9 ? -1 : dist[n - 1][m - 1];
    }
};