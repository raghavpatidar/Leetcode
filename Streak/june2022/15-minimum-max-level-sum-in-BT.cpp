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

Problem : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
Day : 404
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
class Solution {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };
public:
    int maxLevelSum(TreeNode* root) {
        int sum = root->val, minLevel = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({ root , 1 });
        while (q.size() > 0) {
            int sz = q.size();
            int levelSum = 0;
            int currLevel = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front().first;
                int level = q.front().second;
                q.pop();
                currLevel = level;

                levelSum += curr->val;

                if (curr->left) {
                    q.push({ curr->left ,level + 1 });
                }

                if (curr->right) {
                    q.push({ curr->right , level + 1 });
                }
            }
            if (levelSum > sum) {
                minLevel = currLevel;
                sum = levelSum;
            }
        }
        return minLevel;
    }
};