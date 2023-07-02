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

Problem : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
Day : 397
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i = 0;
        int j = grid[0].size() - 1;
        int count = 0;
        // similar to seach in row wise sorted matrix 
        while (i < grid.size() && j >= 0)
        {
            if (grid[i][j] < 0)
            {
                count += (grid.size() - i); // add Negative Count = Total Row - current Row
                j--; //decrease the Column Pointer ( j--)
            }
            else if (grid[i][j] >= 0)
            {
                i++; // increase the Row pointer ( i++ )
            }
        }
        return count;
    }
};