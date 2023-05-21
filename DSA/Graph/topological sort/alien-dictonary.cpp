//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
// Day : 

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    vector<int> topo(int n, vector<int>adj[]) {
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
        //if(ans.size() == n )return true;
        //else return false;
        return ans;
    }

    pair<char, char> getdiff(string& a, string& b) {
        int i = 0;
        for (i = 0; i < min(a.size(), b.size());i++) {
            if (a[i] != b[i]) {
                return { a[i],b[i] };
            }
        }
        return { 'A' , 'A' };
    }
    string findOrder(string dict[], int n, int k) {
        vector<int>adj[k];
        for (int i = 0; i < n - 1; i++) {
            pair<char, char> p = getdiff(dict[i], dict[i + 1]);
            if (p.first == 'A')continue;
            else {
                // cout<<p.first<<" "<<p.second<<endl;
                adj[p.first - 'a'].push_back(p.second - 'a');
            }
        }


        vector<int>ans = topo(k, adj);
        string s = "";
        for (int i = 0; i < ans.size();i++) {
            s.push_back('a' + ans[i]);
            // cout<<i<<" -- > "<<ans[i] <<" " <<((char)('a' + (char)ans[i]))<<endl;
        }
        return s;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if (f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends