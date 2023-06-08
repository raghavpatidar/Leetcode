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

Problem : https://www.codingninjas.com/codestudio/problems/colorful-knapsack_630415
Day : 3
*/

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

int cnt = 1e9;
int solve(int idx, int target, int m, map<int, vector<int>>& mp
    , map<pair<int, int>, int>& dp) {
    //base
    if (idx == m) {

        cnt = min(cnt, target);
        // cout<<idx<<" "<<target<<endl;
        return target;
    }
    if (target <= 0) {
        return 1e9;
    }

    if (dp.find({ idx , target }) != dp.end())return dp[{idx, target}];
    //pick 1 from one color
    int curr = 1e9;

    for (auto j : mp[idx + 1]) {
        if (target >= j) {
            int temp = j + solve(idx + 1, target - j, m, mp, dp);
            // cout<<temp<<endl;
            curr = min(curr, temp);
        }
    }
    return dp[{idx, target}] = curr;

}

int colorfulKnapsack(int w[], int c[], int n, int m, int x)
{
    map<int, vector<int>>mp;
    map<pair<int, int>, int>dp;
    for (int i = 0; i < n; i++) {
        mp[c[i]].push_back(w[i]);
    }
    int ans = solve(0, x, m, mp, dp);
    // cout<<ans<<endl;
    return cnt == 1e9 ? -1 : cnt;
}

