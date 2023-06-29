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

Problem : https://leetcode.com/problems/shortest-path-to-get-all-keys/description/
Day : 418s
*/

#include<bits/stdc++.h>
using namespace std;

int shortestPathAllKeys(vector<string>& grid) {
    int m = grid.size(), n = m ? grid[0].size() : 0;
    if (!m || !n) return 0;
    int path = 0, K = 0;
    vector<int> dirs = { 0,-1,0,1,0 };
    vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(64, 0))); //at most 6 keys, using bitmap 111111
    queue<pair<int, int>> q; //<postion, hold keys mapping>
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            if (grid[i][j] == '@') {
                q.push({ i * n + j,0 });
                visited[i][j][0] = 1;
            }
            if (grid[i][j] >= 'A' && grid[i][j] <= 'F') K++; //total alpha number
        }
    }
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0;i < size;i++) {
            int a = q.front().first / n, b = q.front().first % n;
            int carry = q.front().second;
            q.pop();
            if (carry == ((1 << K) - 1)) return path; //if all keys hold, just return 
            for (int j = 0;j < 4;j++) {
                int x = a + dirs[j], y = b + dirs[j + 1], k = carry;
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#') continue;
                if (grid[x][y] >= 'a' && grid[x][y] <= 'f') {
                    k = carry | (1 << (grid[x][y] - 'a')); //update hold keys
                }
                else if (grid[x][y] >= 'A' && grid[x][y] <= 'F') {
                    if (!(carry & (1 << (grid[x][y] - 'A')))) continue;
                }
                if (!visited[x][y][k]) {
                    visited[x][y][k] = 1;
                    q.push({ x * n + y,k });
                }
            }
        }
        path++;
    }
    return -1;
}