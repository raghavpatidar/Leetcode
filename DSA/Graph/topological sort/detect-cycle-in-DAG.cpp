//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
// Day : 


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool topo(int n, vector<int>adj[]) {
        int in[n];
        memset(in, 0, sizeof(in));
        for (int i = 0; i < n; i++) {
            for (auto j : adj[i]) {
                in[j]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n;i++) {
            if (!in[i])q.push(i);
        }
        vector<int>ans;
        while (q.size()) {
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            for (auto i : adj[curr]) {
                in[i]--;
                if (in[i] == 0) {
                    q.push(i);
                }
            }
        }
        //for(auto i: ans)cout<<i<<" ";
        if (ans.size() == n)return true;
        else return false;
        //return ans;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        return !topo(V, adj);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends