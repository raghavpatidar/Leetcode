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

Problem : https://leetcode.com/problems/equal-row-and-column-pairs/
Day : 402
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool check(int x, int y, vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            if (grid[x][i] != grid[i][y])return false;
        }
        cout << endl;
        return true;
    }
    int equalPairs(vector<vector<int>>& gird) {
        int ans = 0;
        for (int i = 0; i < gird.size();i++) {
            for (int j = 0; j < gird[0].size();j++) {
                if (check(i, j, gird)) {
                    // cout<<i<<" "<< j<<endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};