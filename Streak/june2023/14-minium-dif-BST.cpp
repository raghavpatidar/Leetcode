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

Problem : https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
Day : 403
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int inorderTraverse(TreeNode* root, int& val, int& min_dif) {
        if (root->left != NULL)
            inorderTraverse(root->left, val, min_dif);
        if (val >= 0)
            min_dif = min(min_dif, root->val - val);
        val = root->val;
        if (root->right != NULL)
            inorderTraverse(root->right, val, min_dif);
        return min_dif;
    }
    int getMinimumDifference(TreeNode* root) {
        auto min_dif = INT_MAX, val = -1;
        return inorderTraverse(root, val, min_dif);
    }

};