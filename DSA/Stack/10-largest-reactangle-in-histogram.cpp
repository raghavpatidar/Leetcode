//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/largest-rectangle-in-histogram/
// Day : 
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> nsl(vector<int>& v) {
        stack<pair<int, int>> st;
        vector<int>ans;
        for (int i = 0; i < v.size(); i++) {
            int temp = -1;
            if (st.size() > 0) {
                while (st.size() > 0 and st.top().first >= v[i])st.pop();
                if (st.size() > 0)temp = st.top().second;
            }

            ans.push_back(temp);
            st.push({ v[i] , i });
        }
        return ans;
    }
    vector<int> nsr(vector<int>& v) {
        stack<pair<int, int>> st;
        vector<int> ans;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int temp = v.size();
            if (st.size() > 0) {
                while (st.size() > 0 and st.top().first >= v[i])st.pop();
                if (st.size() > 0)temp = st.top().second;
            }

            ans.push_back(temp);
            st.push({ v[i] , i });
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 1)return heights[0];
        vector<int> left = nsl(heights);
        vector<int> right = nsr(heights);
        vector<int> width(heights.size());
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {

            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }

        return ans;
    }
};