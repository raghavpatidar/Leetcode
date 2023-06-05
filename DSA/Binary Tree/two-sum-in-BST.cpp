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

Problem : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/958925293/
Day :
*/

#include<bits/stdc++.h>
using namespace std;



//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class BSTIterator {
public:
    bool isreverse = false;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* node, bool reverse) {
        isreverse = reverse;

        pushAll(node);
    }

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            if (isreverse)node = node->right;
            else node = node->left;
        }
    }
    int next() {
        TreeNode* curr = st.top();
        st.pop();
        if (isreverse)pushAll(curr->left);
        else pushAll(curr->right);
        return curr->val;
    }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, 0);
        BSTIterator r(root, 1);
        int i = l.next();
        int j = r.next();
        while (i < j) {
            if (i + j == k)return true;
            else if (i + j < k)i = l.next();
            else j = r.next();
        }
        return false;

    }
};