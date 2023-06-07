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

Problem : https://leetcode.com/problems/maximal-square/description/
Day : 2
*/

#include<bits/stdc++.h>
using namespace std;

//approach 1
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') dp[i][j] = matrix[i][j] - '0';
                else {
                    dp[i][j] = min({ dp[i - 1][j - 1] , dp[i][j - 1] , dp[i - 1][j] }) + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;

    }
};

//approach 2
class Solution {
public:
    vector<int> nsl(vector<int>v) {
        stack<int>st;
        vector<int> ans;
        for (int i = 0; i < v.size(); i++) {
            if (st.size() > 0) {
                while (st.size() > 0 and v[st.top()] >= v[i])st.pop();
                if (st.size() == 0)ans.push_back(-1);
                else ans.push_back(st.top());
            }
            else {
                ans.push_back(-1);
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nsr(vector<int>v) {
        stack<int>st;
        vector<int> ans;
        int n = v.size();
        for (int i = v.size() - 1; i >= 0; i--) {
            if (st.size() > 0) {
                while (st.size() > 0 and v[st.top()] >= v[i])st.pop();
                if (st.size() == 0)ans.push_back(n);
                else ans.push_back(st.top());
            }
            else {
                ans.push_back(n);
            }
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int maxHistogram(vector<int> v) {
        vector<int>left = nsl(v);
        vector<int>right = nsr(v);
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            int w = (right[i] - left[i] - 1);
            int h = v[i];
            int area = min(h, w) * min(h, w);
            ans = max(ans, area);
        }
        return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)dp[0][j] = matrix[0][j] - '0';
        int ans = maxHistogram(dp[0]);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m;j++) {
                if (matrix[i][j] == '0')dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j] + 1;
            }
            ans = max(ans, maxHistogram(dp[i]));
        }
        return ans;
    }
};