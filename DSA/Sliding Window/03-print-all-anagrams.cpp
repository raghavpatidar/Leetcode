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

Problem :  https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/958635768/
Day :
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> m, mp;
        int k = p.size(), n = s.size();
        for (auto i : p)m[i]++;
        for (int i = 0; i < k; i++) {
            mp[s[i]]++;
        }
        //  int ans = 0;
        vector<int> ans;
        int start = 0;
        if (mp == m)ans.push_back(start);
        for (int i = k; i < n; i++) {
            mp[s[start]]--;
            if (mp[s[start]] == 0)mp.erase(s[start]);
            mp[s[i]]++;
            if (mp == m)ans.push_back(start + 1);
            start++;
        }
        return ans;
    }
};