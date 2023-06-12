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

Problem : https://leetcode.com/problems/palindrome-partitioning-ii/
Day :
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPalindrome(int i, int j, string& s) {
        while (i <= j) {
            if (s[i] != s[j])return false;
            i++, j--;
        }
        return true;
    }
    int solve(int i, string& s, vector<int>& dp) {

        if (i >= s.size() or checkPalindrome(i, s.size() - 1, s)) return 0;
        int mini = 1e9;
        if (dp[i] != -1)return dp[i];

        for (int k = i; k < s.size(); k++) {
            if (checkPalindrome(i, k, s)) {
                int temp = 1 + solve(k + 1, s, dp);
                mini = min(temp, mini);
            }
        }
        return dp[i] = mini;

    }
    int minCut(string s) {
        if (s.size() == 0)return 0;
        vector<int>dp(s.size() + 1, -1);
        return solve(0, s, dp);
    }

};