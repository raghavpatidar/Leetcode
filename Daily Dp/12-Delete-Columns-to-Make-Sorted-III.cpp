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

Problem : https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
Day : 12
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int prev, int n, vector<string>& strs, vector<vector<int>>& dp) {
        //base
        if (idx == n)return 0;
        //memo
        if (dp[idx][prev + 1] != -1)return dp[idx][prev + 1];

        int del = 1e9, noDel = 1e9;
        bool allIncreasing = true;
        if (prev != -1) {
            for (int i = 0; i < strs.size(); i++) {
                if (strs[i][prev] > strs[i][idx])allIncreasing = false;
            }
        }
        if (allIncreasing) {
            del = 1 + solve(idx + 1, prev, n, strs, dp);
            noDel = solve(idx + 1, idx, n, strs, dp);
        }
        else del = 1 + solve(idx + 1, prev, n, strs, dp);

        return dp[idx][prev + 1] = min(del, noDel);
    }
    int minDeletionSize(vector<string>& strs) {
        int len = strs[0].size();
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, -1));
        return solve(0, -1, strs[0].size(), strs, dp);
    }
};



// ├──solve(0, -1)
// |    ├──solve(1, -1)
// |    |    ├──solve(2, -1)
// |    |    |    ├──solve(3, -1)
// |    |    |    |    ├──solve(4, -1)
// |    |    |    |    |    ├──solve(5, -1)
// |    |    |    |    Returned from del: 1
// |    |    |    |    |    ├──solve(5, 4)
// |    |    |    |    Returned from No delete: 0
// |    |    |    Returned from del: 1
// |    |    |    |    ├──solve(4, 3)
// |    |    |    |    |    ├──solve(5, 4)
// |    |    |    |    Returned from delete: 1
// |    |    |    Returned from No delete: 1
// |    |    Returned from del: 2
// |    |    |    ├──solve(3, 2)
// |    |    |    |    ├──solve(4, 2)
// |    |    |    |    |    ├──solve(5, 4)
// |    |    |    |    Returned from delete: 1
// |    |    |    Returned from del: 2
// |    |    |    |    ├──solve(4, 3)
// |    |    |    |    DP hit!
// |    |    |    Returned from No delete: 1
// |    |    Returned from No delete: 1
// |    Returned from del: 2
// |    |    ├──solve(2, 1)
// |    |    |    ├──solve(3, 2)
// |    |    |    DP hit!
// |    |    Returned from delete: 2
// |    Returned from No delete: 2
// Returned from del: 3
// |    ├──solve(1, 0)
// |    |    ├──solve(2, 1)
// |    |    DP hit!
// |    Returned from delete: 3
// Returned from No delete: 3






    // bool checkIncreasing(int idx, int prev, int n, vector<string>& strs) {
    //     if (prev == -1) return true;
    //     for (int i = 0; i < strs.size(); i++) {
    //         if (strs[i][prev] > strs[i][idx]) return false;
    //     }
    //     return true;
    // }
    //     string getIndentation(int level) {
    //     string indent;
    //     for (int i = 0; i < level; i++) {
    //         if(i == level-1){
    //         indent+= "├──";
    //         indent += "────";
    //         }else{
    //             indent += "|     ";
    //         }
    //     }
    //     return indent;
    // }


    // int solve(int idx, int prev, int n, vector<string>& strs, vector<vector<int>>& dp) {
    //     cout << getIndentation(idx) << "solve(" << idx << ", " << prev << ")" << endl;
    //     if (idx == n) return 0;
    //     if (dp[idx][prev + 1] != -1) {
    //         cout << getIndentation(idx) << "DP hit!" << endl;
    //         return dp[idx][prev + 1];
    //     }
    //     int del = 1e9, noDel = 1e9;
    //     int allIncreasing = checkIncreasing(idx, prev, n, strs);
    //     if (allIncreasing) {
    //         del = 1 + solve(idx + 1, prev, n, strs, dp);
    //         cout << getIndentation(idx) << "Returned ("<< idx <<","<< prev <<") delete: " << del << endl;
    //         noDel = solve(idx + 1, idx, n, strs, dp);
    //         cout << getIndentation(idx) << "Returned ("<< idx <<","<< prev <<") No delete: " << noDel << endl;
    //     } else {
    //         del =1 + solve(idx + 1, idx, n, strs, dp);
    //         cout << getIndentation(idx) << "Returned ("<< idx <<","<< prev <<") delete: " << del << endl;
    //     }
    //     int ans = min(del , noDel);
    //     cout<<getIndentation(idx)<<" Return min("<< idx <<","<< prev <<") = "<< ans<<endl;
    //     return dp[idx][prev + 1] = min(del, noDel);
    // }