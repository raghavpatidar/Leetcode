//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to return list containing vertices in Topological order. 
    vector<int> topoSort(int n, vector<int> adj[])
    {
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
        //for(int i = 0; i < n ; i++){
        //    cout<<"in --> "<<in[i]<<" , "<<i<<" --> ";
        //    for(auto j : adj[i]){
        //        cout<<j<<" ";
        //    }
        //    cout<<endl;
        //}
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
        //for(auto i : ans)cout<<i<<" ";
        return ans;

    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int>& res, vector<int> adj[]) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends