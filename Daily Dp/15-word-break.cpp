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

Problem : https://leetcode.com/problems/word-break/
Day :
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int idx, map<string, int>& m, string& s, vector<int>& dp) {
        // cout<<idx<<" ";
        if (idx == s.size())return true;
        if (idx > s.size())return false;


        if (dp[idx] != -1)return dp[idx];

        int use = false;
        string k = "";
        for (int i = idx; i < s.size(); i++) {
            k.push_back(s[i]);
            // cout<<k<<endl;
            if (m.find(k) != m.end()) {
                use = use || solve(i + 1, m, s, dp);
            }
        }
        // cout<<endl;
        return dp[idx] = use;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, int> m;
        for (auto i : wordDict)m[i] = 1;
        vector<int> dp(s.size() + 1, -1);
        return solve(0, m, s, dp);
    }
};