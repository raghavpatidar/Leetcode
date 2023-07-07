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

Problem : https://leetcode.com/problems/maximize-the-confusion-of-an-exam/submissions/988735447/
Day : 426
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(string& s, char b, int& k) {
        int left = 0, res = 0, size = s.size(), cnt = 0;
        for (int i = 0;i < size;i++) {
            if (s[i] == b)
                cnt++;
            while (cnt > k) {
                if (s[left] == b)
                    cnt--;
                left++;
            }
            res = max(i - left + 1, res);
        }
        return res;
    }
    int maxConsecutiveAnswers(string s, int k) {
        return max(solve(s, 'F', k), solve(s, 'T', k));
    }
};