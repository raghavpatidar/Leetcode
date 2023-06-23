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

Problem : https://leetcode.com/problems/word-break-ii/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(int idx, map<string, int>& m, string& s, vector<string>& ans, string& curr) {
        if (idx == s.size()) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        if (idx > s.size())return;



        string k = "";
        for (int i = idx; i < s.size(); i++) {
            k.push_back(s[i]);
            string temp = curr;
            if (m.find(k) != m.end()) {
                temp.append(k);
                temp.push_back(' ');
                solve(i + 1, m, s, ans, temp);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string, int> m;
        for (auto i : wordDict)m[i] = 1;
        vector<string >ans;
        string curr = "";
        solve(0, m, s, ans, curr);
        return ans;
    }
};
