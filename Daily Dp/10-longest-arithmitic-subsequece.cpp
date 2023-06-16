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

Problem : https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
Day :
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        map<int, int> m;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = arr[i] - difference;
            if (m.count(x)) {
                m[arr[i]] = 1 + m[x];
            }
            else {
                m[arr[i]] = 1;
            }
            ans = max(ans, m[arr[i]]);
        }
        return ans;
    }
};