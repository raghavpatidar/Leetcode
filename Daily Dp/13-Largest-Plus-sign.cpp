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

Problem : https://leetcode.com/problems/largest-plus-sign/description/
Day :
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int up, down, left, right, curr;
    Node() {
        up = down = left = right = curr = 0;
    }
};

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> mat(n, vector<int>(n, 1));
        for (auto i : mines)mat[i[0]][i[1]] = 0;
        vector<vector<int>> lef, rig, top, bot;
        lef = rig = top = bot = mat;
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                int x = n - i - 1;
                int y = n - j - 1;
                if ((i > 0) && top[i][j]) top[i][j] += top[i - 1][j];
                if ((j > 0) && lef[i][j]) lef[i][j] += lef[i][j - 1];
                if ((x < n - 1) && bot[x][y]) bot[x][y] += bot[x + 1][y];
                if ((y < n - 1) && rig[x][y]) rig[x][y] += rig[x][y + 1];
            }
        }

        int ans = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                ans = max(ans, min({ lef[i][j], rig[i][j], top[i][j], bot[i][j] }));

        return ans;
    }
};