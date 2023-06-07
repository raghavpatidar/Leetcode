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

Problem : https://leetcode.com/problems/predict-the-winner/description/
Day : 2
*/

#include<bits/stdc++.h>
using namespace std;

//pick from start
    //then second player has two options 
        //  1 he can pick from start which is i+1 so player 1 have i+2 next 
        //  2 he can pick from end which is j-1 so plaayer 1 have open for first is i+1,j-1
//pick from end
    //then second player has two options 
        //  1 he can pick from start which is i+1 so player 1 have i+2 next 
        //  2 he can pick from end which is j-1 so plaayer 1 have open for first is i+1,j-1
class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        {
            if (i > j)return 0;
            if (i == j)return nums[i];

            if (dp[i][j] != -1)return dp[i][j];

            int startPick = nums[i] + min(solve(i + 2, j, nums, dp), solve(i + 1, j - 1, nums, dp));
            int endPick = nums[j] + min(solve(i, j - 2, nums, dp), solve(i + 1, j - 1, nums, dp));

            int currSum = max(startPick, endPick);
            return dp[i][j] = currSum;

        }
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int totalSum = 0;
        for (auto i : nums)totalSum += i;
        int suma = solve(0, n - 1, nums, dp);
        int sumb = totalSum - suma;
        cout << suma << " " << sumb << endl;
        return suma >= sumb;
    }
};