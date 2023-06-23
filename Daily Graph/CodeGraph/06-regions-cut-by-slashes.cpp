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

Problem : https://leetcode.com/problems/regions-cut-by-slashes/
Day :
*/

#include<bits/stdc++.h>
using namespace std;
class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 0);
    }

    int findPar(int x) {
        if (parent[x] == x)return x;
        return parent[x] = findPar(parent[x]);
    }


    void uniteByRank(int x, int y) {
        int parX = findPar(x);
        int parY = findPar(y);

        if (parX != parY) {
            if (rank[parX] == rank[parY]) {
                rank[parX]++;
                parent[parX] = parY;
            }
            else if (rank[parX] < rank[parY]) {
                parent[parX] = parY;
            }
            else {
                parent[parY] = parY;
            }
        }
    }
};


class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int dot = n + 1;
        DSU dsu(dot * dot + 1);
        for (int i = 0; i < dot; i++) {
            for (int j = 0; j < dot; j++) {
                if (i == 0 || j == 0 || i == dot - 1 || j == dot - 1) {
                    int cellno = i * dot + j;
                    if (cellno != 0)
                        dsu.uniteByRank(0, cellno);
                }
            }
        }
        cout << endl;
        int ans = 1;

        for (int i = 0;i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    int a = dot * (i + 1) + j;
                    int b = dot * (i)+j + 1;

                    int px = dsu.findPar(a);
                    int py = dsu.findPar(b);
                    if (px == py)ans++;
                    dsu.uniteByRank(px, py);
                }
                else if (grid[i][j] == '\\') {
                    int a = dot * (i)+j;
                    int b = dot * (i + 1) + j + 1;
                    int px = dsu.findPar(a);
                    int py = dsu.findPar(b);
                    if (px == py)ans++;
                    dsu.uniteByRank(px, py);
                }
            }

        }
        return ans;
    }
};

// [0 1 2 3 ]
// [4 5 6 7 ]
// [8 9 10 11]
// [12 13 14 15]



// i*m + j