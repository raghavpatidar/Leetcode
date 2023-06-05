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

Problem : https://leetcode.com/problems/check-if-it-is-a-straight-line/submissions/964520589/
Day : 394
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dY = coordinates[1][1] - coordinates[0][1];
        int dX = coordinates[1][0] - coordinates[0][0];
        for (int i = 2; i < coordinates.size(); i++) {
            auto p = coordinates[i];
            if (dX * (p[1] - coordinates[0][1]) != dY * (p[0] - coordinates[0][0]))
                return false;
        }
        return true;
    }
};