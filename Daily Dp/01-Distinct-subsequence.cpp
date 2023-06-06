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

Problem : https://www.codingninjas.com/codestudio/problems/distinct-subsequences_799558
Day : 1
*/

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 

int distinctSubsequences(string s) {
    map<char, int> m;
    vector<int>dp(s.size() + 1);
    dp[0] = 1;
    int mod = 1e9 + 7;
    for (int i = 1; i <= s.size();i++) {
        dp[i] = (2 * dp[i - 1]) % mod;
        if (m.find(s[i - 1]) != m.end()) {
            int repeateidx = m[s[i - 1]] - 1;
            dp[i] = (dp[i] - dp[repeateidx]);
            dp[i] %= mod;
        }
        m[s[i - 1]] = i;
    }
    int n = s.size();
    if (dp[n] < 0)dp[n] += mod;
    return dp[n];
}