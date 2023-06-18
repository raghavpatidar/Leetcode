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

Problem : https://leetcode.com/problems/make-array-strictly-increasing/
Day :
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPos(int j, int curr, int m, vector<int>& arr2) {
        for (int i = j; i < m; i++) {
            if (curr < arr2[i])return i;
        }
        return m;
    }
    int dp[2002][2002][2];
    int solve(int i, int j, int prev, int n, int m, vector<int>& arr1, vector<int>& arr2) {
        if (i >= n)return 0;
        int prevElement = prev ? i == 0 ? INT_MIN : arr1[i - 1] : arr2[j];
        if (dp[i][j][prev] != 0) {
            return dp[i][j][prev];
        }
        //  int pos = findPos(j , prevElement , m , arr2);
        int pos = upper_bound(begin(arr2) + j, end(arr2), prevElement) - begin(arr2);
        int swap = 1e9, noSwap = 1e9;
        if (prevElement < arr1[i]) {
            noSwap = solve(i + 1, pos, 1, n, m, arr1, arr2);
        }
        if (pos < m) {
            swap = 1 + solve(i + 1, pos, 0, n, m, arr1, arr2);
        }
        return dp[i][j][prev] = min(swap, noSwap);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int ans = solve(0, 0, 1, arr1.size(), arr2.size(), arr1, arr2);
        // cout<<ans<<endl;
        return ans >= 1e9 ? -1 : ans;
    }
};
