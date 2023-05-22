//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// Day : 


// lgoic is simple first get topological ordering then start increamenting the dist value accordingly for each child till end

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:


    vector<int> shortestPath(int n, int M, vector<vector<int>>& edges) {
        vector<pair<long long int, long long int>> adj[n];
        vector<long long int> in(n, 0);
        vector<long long int> order;
        long long int inf = 1e9;
        for (auto i : edges) {
            adj[i[0]].push_back({ i[1] , i[2] });
            in[i[1]]++;
        }
        queue<long long int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (q.size() > 0) {
            long long int curr = q.front();
            q.pop();
            order.push_back(curr);
            for (auto i : adj[curr]) {
                in[i.first]--;
                if (in[i.first] == 0)q.push(i.first);
            }
        }
        vector<long long int> dist(n, inf);
        dist[0] = 0;
        for (auto i : order) {
            for (auto child : adj[i]) {
                long long int u = i;
                long long int v = child.first;
                long long int w = child.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (dist[i] != inf) {
                ans[i] = dist[i];
            }
            else {
                ans[i] = -1;
            }
        }

        return ans;




    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x; cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends