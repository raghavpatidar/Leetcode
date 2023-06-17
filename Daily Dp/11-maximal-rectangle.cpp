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

Problem : https://leetcode.com/problems/maximal-rectangle/
Day :
*/

#include<bits/stdc++.h>
using namespace std;

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
            int area = (h * w);
            ans = max(ans, area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m, 0);
        for (int j = 0; j < m; j++)prev[j] = matrix[0][j] - '0';
        int ans = maxHistogram(prev);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m;j++) {
                if (matrix[i][j] == '0')prev[j] = 0;
                else prev[j] = prev[j] + 1;
            }
            ans = max(ans, maxHistogram(prev));
            // prev = curr;
        }
        return ans;

    }
};