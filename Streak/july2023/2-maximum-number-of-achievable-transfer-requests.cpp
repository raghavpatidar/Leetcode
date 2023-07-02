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

Problem : https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool check(vector<int>& vis) {
        for (auto i : vis)if (i != 0)return false;
        return true;
    }
    int solve(int idx, vector<vector<int>>& requests, vector<int>& vis) {
        if (idx == 0) {
            return check(vis) ? 0 : -1e9;
        }
        int noPick = solve(idx - 1, requests, vis);
        int u = requests[idx - 1][0], v = requests[idx - 1][1];
        vis[u]--, vis[v]++;
        int pick = 1 + solve(idx - 1, requests, vis);
        vis[u]++, vis[v]--;
        return max(noPick, pick);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> vis(n + 1, 0);
        return solve(requests.size(), requests, vis);

    }
};