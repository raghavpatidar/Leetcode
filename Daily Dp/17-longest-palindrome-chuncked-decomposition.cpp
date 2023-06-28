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

Problem : https://leetcode.com/problems/longest-chunked-palindrome-decomposition/
Day :
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(string& a, string& b) {
        for (int i = 0; i < a.size();i++) {
            if (a[i] != b[b.size() - 1 - i])return false;
        }
        return true;
    }

    int solve(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i > j)return 0;
        if (i == j)return 1;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        string a = "", b = "";
        int l = i, r = j;
        int range = j - i + 1;
        int sub = 0;
        // bool ok = false;
        // cout<<i<<" "<<j<<endl;
        while (l <= r) {
            a.push_back(s[l]);
            b.push_back(s[r]);
            l++, r--;
            //  cout<<a<<" - "<< b<<endl;
            if (check(a, b)) {
                //  ok = true;
                // cout<<a<<" in "<< b<<endl;
                int pos = a.size();
                int x = a.size() == range ? 1 : 2;
                sub = max(sub, x + solve(i + pos, j - pos, s, dp));
            }
        }
        // cout<<endl;

        return dp[i][j] = max(sub, 1);



    }
    int longestDecomposition(string text) {
        vector<vector<int>> dp(text.size() + 1, vector<int>(text.size() + 1, -1));
        return solve(0, text.size() - 1, text, dp);
    }
};