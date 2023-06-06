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

Problem : https://www.codingninjas.com/codestudio/problems/dice-throws_799924
Day : 1
*/

#include<bits/stdc++.h>
using namespace std;

//memoizaation
int solve(int idx, int face, int target, vector<vector<int>>& dp, int mod) {

    if (idx == 0 and target == 0)return 1;
    if (target == 0 || idx == 0)return 0;
    if (dp[idx][target] != -1)return dp[idx][target];
    int cnt = 0;
    for (int j = 1; j <= face; j++) {
        if (target >= j) {
            cnt = (cnt % mod + solve(idx - 1, face, target - j, dp, mod) % mod) % mod;
        }
    }
    return dp[idx][target] = cnt % mod;
}

//tabulation
int diceThrows(int d, int f, int s) {
    vector<vector<int>> dp(d + 1, vector<int>(s + 1, -1));
    int mod = 1e9 + 7;
    for (int i = 0;i <= d; i++)dp[i][0] = 0;
    for (int j = 0; j <= s; j++)dp[0][j] = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= s; j++) {
            int cnt = 0;
            for (int k = 1; k <= f; k++) {
                if (j >= k) {
                    cnt = (cnt % mod + dp[i - 1][j - k]) % mod;
                }
            }
            dp[i][j] = cnt % mod;
        }
    }
    return dp[d][s] % mod;

}

//space optimization
int diceThrows(int d, int f, int s) {
    int mod = 1e9 + 7;
    vector<int> prev(s + 1, 0), curr(s + 1, 0);
    for (int j = 0; j <= s; j++)prev[j] = 0;
    prev[0] = 1;
    for (int i = 1; i <= d; i++) {
        curr[0] = 0;
        for (int j = 1; j <= s; j++) {
            int cnt = 0;
            for (int k = 1; k <= f; k++) {
                if (j >= k) {
                    cnt = (cnt % mod + prev[j - k]) % mod;
                }
            }
            curr[j] = cnt % mod;
        }
        prev = curr;
    }
    return prev[s] % mod;

}