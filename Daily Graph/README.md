# Daily Graph problem - Started  June, 13, 2023 .

# Table of Content

- [Daily Graph problem - Started  June, 13, 2023 .](#daily-graph-problem---started--june-13-2023-)
- [Table of Content](#table-of-content)
- [Day 1](#day-1)
  - [310. Minimum Height Trees](#310-minimum-height-trees)
  - [684. Redundant Connection](#684-redundant-connection)





# Day 1
## [310. Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/) 

> A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
Return a list of all MHTs' root labels. You can return the answer in any order.
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

<code >Logic</code>

```quote

1. Start Removing all leaf nodes 
2. then new leafe node become then reomve that nodes
3. think of Topological sorting
4. when we have left with last 2 nodes 
5. check that theey can be our MHT's root

```

[Code Link](./CodeGraph/01-Minimum-Height-Tree-Root.cpp)

<details><summary>Code</summary>

```cpp

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0), ans; //vector<int> indegree keeps count of the number of nodes approaching a node
        
        for(auto &e : edges){   //Creating an adjacency matrix for the given graph
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;

            indegree[e[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n;i++){
            if(indegree[i]==1) q.push(i), indegree[i]--; //add all the leaf nodes to the queue
        } 
        
        while(!q.empty()){
            int s = q.size();
            ans.clear();
            for(int i=0; i<s;i++){
                int curr = q.front(); q.pop();
                ans.push_back(curr);
                for(auto child : graph[curr]){ //For each node, attached to the leaf niodes, we decrement the indegree i.e remove the leaf nodes connected to them. We keep on doing this until we reach the middle nodes.
                    indegree[child]--;
                    if(indegree[child]==1) q.push(child);   
                }
            }
        }
        if(n==1) ans.push_back(0); //If there is only 1 node in the graph, the min height is 0, with root being '0'
        return ans;
        
    }
};

```
</details>

<br> 





## [684. Redundant Connection]() 

> In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

<code >Logic</code>

```quote

1. Topological Sort --> Remove all the edges and mark them visited all edges in topo sort 
2. Union Find --> add Edge if they are not added else if they alredy connected then return the current edges as it is our redundant edge.

```
[Code Link](./CodeGraph/02-Redundant-Connection.cpp)

<details><summary>Code</summary>

```cpp

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // {u,v} --> {idx , visited};
        map<  pair<int,int>  , pair<int, int> > m;
        int n = edges.size();
        vector<int> adj[n + 1];
        vector<int> in(n + 1 , 0);
        int k = 1;
        
        for(auto i : edges){
            int u = i[0] , v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            m[{u , v}] = { k , 0};
            m[{v , u}] = {k , 0};
            in[u]++ , in[v]++;
            k++;
        }
        queue<pair<int, int>> q;
        for(int i = 1 ; i<= n ;i++){
            if(in[i] == 1){
                q.push({ i , -1});
                in[i]--;
            }
        }
        while(q.size() > 0){
            int curr = q.front().first;
            int par = q.front().second;
            q.pop();
            if(par != -1){
                m[{curr , par}].second = 1;
                m[{par , curr}].second = 1;
            }

            for(auto i : adj[curr]){
                m[{curr , i}].second = 1;
                m[{i , curr}].second = 1;
                   in[i]--;
                if(in[i] == 1){
                   q.push({i , curr});
                }
            }
        }

        pair<int, int> p;
        int idx = 0;

        for(auto [i , j] : m ){
            if(j.second == 0){
                if(idx < j.first){
                    idx = j.first;
                    p = { i.first , i.second};
                }
            }
        }

        pair<int, int> p2;
        p2.first = p.second;
        p2.second = p.first;


        for(auto i : edges){
            int u = i[0] , v = i[1];
            if(p2.first == u and p2.second == v){
                swap(p , p2);
            }
        }

        return {p.first , p.second};

    }
};

```
</details>

<br> 
<br> 


<!-- 

# Day 

## []() 

> Statement

<code >Logic</code>

```quote

Logic

```
[Code Link](./CodeGraph)

<details><summary>Code</summary>

```cpp

Code

```
</details>

<br> 
 -->
