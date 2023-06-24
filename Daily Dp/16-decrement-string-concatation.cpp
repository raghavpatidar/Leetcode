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

Problem : https://leetcode.com/problems/decremental-string-concatenation/description/
Day :
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, char prevfront, char prevback, vector<string>& words, vector<vector<vector<int>>>& dp) {
        // cout<<idx<<" "<<prevfront<<" "<<prevback<<endl;
        if (idx == words.size())return 0;

        if (idx == 0) {
            return words[0].size() + solve(idx + 1, words[idx][0], words[idx].back(), words, dp);
        }

        if (dp[idx][prevfront - 'a'][prevback - 'a'] != -1)return dp[idx][prevfront - 'a'][prevback - 'a'];

        //add front
        int front = words[idx].size() + solve(idx + 1, words[idx][0], prevback, words, dp);
        if (words[idx].back() == prevfront) {
            front--;
        }
        int back = words[idx].size() + solve(idx + 1, prevfront, words[idx].back(), words, dp);
        if (words[idx][0] == prevback) {
            back--;
        }
        return dp[idx][prevfront - 'a'][prevback - 'a'] = min(front, back);
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(30, vector<int>(30, -1)));
        return solve(0, '_', '_', words, dp);
    }
};