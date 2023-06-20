# Daily Graph problem - Started  June, 13, 2023 .

# Table of Content

- [Daily Graph problem - Started  June, 13, 2023 .](#daily-graph-problem---started--june-13-2023-)
- [Table of Content](#table-of-content)
- [Day 1](#day-1)
  - [310. Minimum Height Trees](#310-minimum-height-trees)
  - [684. Redundant Connection](#684-redundant-connection)
- [Day 2](#day-2)
  - [1042. Flower Planting With No Adjacent](#1042-flower-planting-with-no-adjacent)
  - [1361. Validate Binary Tree Nodes](#1361-validate-binary-tree-nodes)
- [Day 3](#day-3)
  - [2192. All Ancestors of a Node in a Directed Acyclic Graph](#2192-all-ancestors-of-a-node-in-a-directed-acyclic-graph)
  - [1514. Path with Maximum Probability](#1514-path-with-maximum-probability)
- [Day 4](#day-4)
  - [1584. Min Cost to Connect All Points](#1584-min-cost-to-connect-all-points)
  - [1462. Course Schedule IV](#1462-course-schedule-iv)
  - [1311. Get Watched Videos by Your Friends](#1311-get-watched-videos-by-your-friends)
- [Day 5](#day-5)
  - [1615. Maximal Network Rank](#1615-maximal-network-rank)
  - [1786. Number of Restricted Paths From First to Last Node](#1786-number-of-restricted-paths-from-first-to-last-node)
  - [2039. The Time When the Network Becomes Idle](#2039-the-time-when-the-network-becomes-idle)





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
[Code Link](./CodeGraph/01-Redundant-Connection.cpp)

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



# Day 2

## [1042. Flower Planting With No Adjacent](https://leetcode.com/problems/flower-planting-with-no-adjacent/) 

> - You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.
> - All gardens have at most 3 paths coming into or leaving it.
> - Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.
> - Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.

 

<code >Logic</code>

```quote

1. Start Dfs
2. pur color of node such that it's child don't have that color 


```
[Code Link](./CodeGraph/02-flowering-no-adjacent-plants.cpp)

<details><summary>Code</summary>

```cpp

class Solution {
public:
    int dfs(int node , vector<int> adj[] , vector<int>&ans , vector<int>&vis){
        // cout<<"node "<<node<<"\n";
        vis[node] = 1;
        int temp[5] = {0};
        for(auto i : adj[node]){
            if(vis[i] == 0){

               int col =  dfs(i , adj , ans , vis);
            //    cout<<"child "<<i <<" "<<col<<endl;
               temp[col] = 1;
            }else{
                temp[ans[i]] = 1;
            }
        }


        for(int i = 1 ; i<= 4;i++){
            if(temp[i] == 0 ){
                ans[node] = i;
                break;
            }
        }

        // cout<<" col - "<<node<<"-->"<<ans[node]<<endl;

        return ans[node];
       

    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1] , vis(n+1 , 0) , ans(n+1 , 0);
        for(auto i : paths){
            int u = i[0] , v= i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1 ; i<= n ;i++){
            if(vis[i] == 0){
                dfs(i , adj , ans , vis);
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
};



// 1----2
// |\  /|
// | \/ |
// | /\ |
// |/  \|
// 4----3

```
</details>

<br> 




## [1361. Validate Binary Tree Nodes](https://leetcode.com/problems/validate-binary-tree-nodes/) 

> - You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.
> - If node i has no left child then leftChild[i] will equal -1, similarly for the right child.
> - Note that the nodes have no values and that we only use the node numbers in this problem.

 

<code >Logic</code>

```quote

1. Condition1 : each node must have Single parent 
2. Condition2 : only 1 Node have No parent which is root
3. Condition3 : check for cycle or disconnected component such 
                Such that dsa call from root node return total N child and N-1 edes must be present


```
[Code Link](./CodeGraph/02-validate-Binary-Tree.cpp)

<details><summary>Code</summary>

```cpp

class Solution {
public:
    // Idea: A valid BT has each node with exactly one parent and exactly one node with no parent (root)
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // map to keep count of no. of parent for each node
        vector<int> parentFreq(n);
        for (int i = 0; i < n; i++)
            if ((leftChild[i] >= 0 and ++parentFreq[leftChild[i]] > 1) or (rightChild[i] >= 0 and ++parentFreq[rightChild[i]] > 1))
                return false;
        // find root (if more than 1 root exist then return false)
        int root = -1;
        for (int i = 0; i < n; i++)
            if (!parentFreq[i]) {
                if (root == -1)
                    root = i;
                else return false;
            }
        // last IMP check: apply dfs on root to calculate total nodes in tree, it should be n
        return countNodes(leftChild, rightChild, root) == n;
    }
    
    int countNodes(vector<int> &left, vector<int> &right, int root) {
        if (root == -1)
            return 0;
        return 1 + countNodes(left, right, left[root]) + countNodes(left, right, right[root]);
    }
};


```
</details>

<br> 
<br> 



# Day 3

## [2192. All Ancestors of a Node in a Directed Acyclic Graph](https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/) 

> You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).
You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.
eturn a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.
A node u is an ancestor of another node v if u can reach v via a set of edges.

 

<code >Logic</code>

```quote

1. TReverse All edges Such that parent of each node become child od each node
2. WE can now do dfs and keep track of child node 


```
[Code Link](./CodeGraph/03-all-ancestor-in-DAG.cpp)

<details><summary>Code</summary>

```cpp

class Solution {
public:
    void addAncestor(int node , int ancestor , vector<set<int>>&ans){
        for(auto i : ans[ancestor]){
            ans[node].insert(i);
        }
        ans[node].insert(ancestor);
    } 
   void dfs(int node  , vector<int> adj[] , vector<set<int>>&ans , vector<int>&vis){
        vis[node] = 1;
        
        for(auto child : adj[node]){
            if(vis[child] == 0 ){
                dfs(child  , adj , ans , vis);
                //go do dfs then add result to our answer list
            }
            addAncestor(node , child , ans);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n] , vis(n , 0) , in(n, 0);
        for(auto i: edges){
            int u = i[0] , v = i[1];
            adj[v].push_back(u);
            in[u]++;
        }
        vector<set<int>> ans(n);
        vector<vector<int>> v(n);
        for(int i = 0; i < n ; i++){
            if(in[i] == 0){
                dfs(i , adj , ans , vis);
            }
        }
        for(int i = 0; i < n ; i++){
            for(auto j : ans[i]){
                v[i].push_back(j);
            }
        }
        return v;
    }
};

```
</details>

<br> 




## [1514. Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/) 

> You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

<code >Logic</code>

```quote

1. Updated Dijkstr's Algo where we imporve check condition
2. dist[child] + w < dist[node] we change it to
3. dist[child]*w < dist[node] condtion 

```
[Code Link](./CodeGraph/03-maximum-probability.cpp)

<details><summary>Code</summary>

```cpp


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];
        int k =0;
        for(auto i : edges){
            int u = i[0], v = i[1] ;
            double w = succProb[k++];
            adj[u].push_back({v , w});
            adj[v].push_back({u , w});
        }
        priority_queue< pair<int,double> , vector<pair<int,double>> , greater<pair<int,double>> > pq;
        pq.push({start , 1.0});
        vector<double> dist(n , 0.0);
        while(pq.size()>0){
            int curr = pq.top().first;
            double d = pq.top().second;
            pq.pop();
            
            for(auto i : adj[curr]){
                double childDist = d* i.second;
                int child = i.first;
               
                if(childDist > dist[child]){
                    dist[child] = childDist;
                    pq.push({child , dist[child]});
                }
            }
        }
        return dist[end];
    }
};

```
</details>

<br>  
<br>  



# Day 4

## [1584. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) 

> You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

<code >Logic</code>

```quote

1. Find Mst of Connect  all possible edges
2. Prime's Algo
3. Krushkal algo

```
[Code Link](./CodeGraph/04-min-cost-to-connect-all-points.cpp)

<details><summary>Code</summary>

```cpp


#define pll pair<int,int>
class Solution {
public:
    int parent[1005];
    int find(int n){
        if(parent[n] == n )return n;
        return parent[n] = find(parent[n]);
    }
    void unite(int a , int b){
        int parA = find(a);
        int parB = find(b);
        parent[parA] = parB;
    }
    int krushkals(vector<vector<int>>& points){
        for(int i = 0; i < points.size();i++)parent[i] = i;
        vector<pair<int, pair<int, int>>> adj;
        
        int n = points.size();
        // generating graph basically with weights
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int weight = abs(points[i][0] - points[j][0]) + 
                             abs(points[i][1] - points[j][1]);//manhattan distance
                
                adj.push_back({weight, {i, j}});
                
            }
        }
        
        // sort on the basis of their edge weight
        sort(adj.begin(), adj.end());
        int sum = 0; 
        for(int i = 0; i < adj.size();i++){
            int a = adj[i].second.first;
            int b = adj[i].second.second;
            if(find(a) != find(b)){
                unite(a , b);
                sum += adj[i].first;
            }
        }
        return sum;
    }

    int prims(vector<vector<int>>& points){
        priority_queue<pll , vector<pll> , greater<pll> >pq;
        pq.push({0 , 0});
        int sum = 0;
        vector<int> vis(points.size()  , 0);
        while(pq.size()>0){
            int wt = pq.top().first;
            int idx = pq.top().second;
            int currX = points[idx][0];
            int currY = points[idx][1];
            pq.pop();
            if(vis[idx] == 1 )continue;


            vis[idx] = 1;
            sum += wt;

            for(int i = 0 ; i < points.size();i++){
                int childX = points[i][0];
                int childY = points[i][1];
                int childWt = abs(childX-currX) + abs(childY - currY);
                if(vis[i] == 0){
                    pq.push({ childWt , i });
                }
            }

        }
        return sum;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        // return prims(points);
        return krushkals(points);

    }
};

```
</details>

<br> 



## [1462. Course Schedule IV](https://leetcode.com/problems/course-schedule-iv/) 

> There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.
For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.
You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.
Return a boolean array answer, where answer[j] is the answer to the jth query.

<code >Logic</code>

```quote
Floyd Warshal
1 Approach 1:  - we can think of all pair shortest path
               - all element exact digonal is inf then add all u->v dist 1
               - using flyod warshall algo 
               - find distance via path
               
TopoSort
2 Approach 2:  - another optimal approach is to use topological sort
               - find ordered for topo sort
               - for each node in order we can add it's child: adj[curr] 
               - pair to our matrix such that matrix[curr][child] = 1;
               - and we need to do this for all nodes such that for each node
               - Time-> O(V*E) Space O(V^2)


```
[Code Link](./CodeGraph/04-course-schedule-IV.cpp)

<details><summary>Code</summary>

```cpp

// another optimal approach is to use topological sort
// find ordered for topo sort
// for each node in order we can add it's child: adj[curr] pair to our matrix such that matrix[curr][child] = 1;
// and we need to do this for all nodes such that for each node Time-> O(V*E) Space O(V^2)


class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        // we can think of all pair shortest path
        //  all element exact digonal is inf then add all u->v dist 1
        // using flyod warshall algo
        vector<vector<int>> isReachable(numCourses , vector<int>(numCourses , 1e9));
        for(int i = 0; i < numCourses ; i++)isReachable[i][i] = 0;
        for(auto i : prerequisites){
            int u = i[0] , v = i[1];
            isReachable[u][v] = 1;
        }
        //via path k
        for(int k = 0 ; k < numCourses ; k++ ){
            for(int i = 0 ; i < numCourses ; i++ ){
                for(int j = 0; j < numCourses;j++){
                    if(isReachable[i][j] > isReachable[i][k] + isReachable[k][j] and isReachable[k][j] != 1e9 and isReachable[i][k] != -1e9 ){
                        isReachable[i][j] = isReachable[i][k]+ isReachable[k][j];
                    }
                }
            }
        }
        vector<bool> ans(queries.size());
        int k = 0;
        for(auto i : queries){
            int u = i[0] , v = i[1];
            if(isReachable[u][v] != 1e9){
                ans[k] = true;
            }else{
                ans[k] = false;
            }
            k++;
        }
        return ans;
    }
};



```
</details>

<br> 



## [1311. Get Watched Videos by Your Friends](https://leetcode.com/problems/get-watched-videos-by-your-friends/) 

> - There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.
> - Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 

<code >Logic</code>

```quote

Note :in BFs always mark visit child when pushing into queye not when taking out from queue
This will not give tle but it will add child many times and time complexity will be increase and may give TLE
i have stress test on one of testcase where 
in first i am getting only 13 nodes at level x with marking visit at pushing into queue
second i am getting 1352 nodes at level x with marking when popping out from queue (duplication of nodes if we reomove duplication)
then we will get the same 13 nodes

Logic is simple Do BFS with level



```
[Code Link](./CodeGraph/04-get-videos-watched-by-friends.cpp)

<details><summary>Code</summary>

```cpp

// Note :in BFs always mark visit child when pushing into queye not when taking out from queue
// This will not give tle but it will add child many times and time complexity will be increase and may give TLE
// i have stress test on one of testcase where 
// in first i am getting only 13 nodes at level x with marking visit at pushing into queue
// second i am getting 1352 nodes at level x with marking when popping out from queue (duplication of nodes if we reomove duplication)
// then we will get the same 13 nodes



class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& adj, int id, int level) {
        int d = 0;
        int n = adj.size();
        queue<int> q;
        q.push(id);
        vector<int> vis(n , 0 ) ;
        vector<string> ans ;
        map<string , int>freq; 
        map<int , vector<string>> mp;
        while(q.size()>0){
            int sz = q.size();
            for(int i = 0;i < sz ;i++){
                int curr = q.front();
                q.pop();
                vis[curr] = 1;
                // find given level update frequency of videos of given friend 
                if(d == level)for(auto j : watchedVideos[curr])freq[j]++;
                
                for(int child : adj[curr]){
                    if(!vis[child]){
                        vis[child] = 1;
                        q.push(child);
                    }
                }
            }
            if(d == level)break;
            d++;
        }
        for(auto [st , f] : freq)mp[f].push_back(st);
        for(auto [f , v] : mp){
            for(auto i : v)ans.push_back(i);
        }
        return ans;

        
    }
};
            

        



            
            

        

```
</details>

<br> 
<br> 



# Day 5

## [1615. Maximal Network Rank](https://leetcode.com/problems/maximal-network-rank/) 

> There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.
The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.
The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.

<code >Logic</code>

```quote

1. count in degree of each node
2. if nodes have edge between them then add indegree and revomve common edge because it is added twice
3. if not connected then just add both node indegree

```
[Code Link](./CodeGraph/05-maximal-network-len.cpp)

<details><summary>Code</summary>

```cpp


class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
         vector<int> in(n , 0 );
         map<pair<int, int> , int>mp;
         for(auto i : roads){
             in[i[0]]++ , in[i[1]]++;
             mp[{i[0] , i[1]}] = 1;
             mp[{i[1] , i[0]}] = 1;
         }
         int ans = 0;
         for(int i = 0; i < n ; i++){
             for(int j = i+1; j < n ; j++){
                int ctr = in[i] + in[j];
                 if(mp[{i ,j}] == 1)ctr--;
                 ans = max(ans , ctr);
             }
         }
        
         return ans;
    }
};

```
</details>

<br> 



## [1786. Number of Restricted Paths From First to Last Node](https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/) 

> Statement

<code >Logic</code>

```quote

1. First find dist array using dikjstras
2. use dp to calculate path initially path wicht reached to end is 1 
3. if we visited node before then add it's child path to out dp[node]+= child only if we have condition dist[node] >= dist[child]


```
[Code Link](./CodeGraph/05-number-of-resctiveted-paths-from-first-to-last-node.cpp)

<details><summary>Code</summary>

```cpp

class Solution {
public:
    vector<int> dikjstras(int n , vector<pair<int,int>> adj[]){
        vector<int> dist(n+2 , INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0 , n});
        dist[n] = 0;
        while(pq.size()>0){
            auto [ d , curr] = pq.top();
            pq.pop();
            for(auto [ child , wt] : adj[curr]){
                if( wt + d < dist[child]){
                    dist[child] = wt + d;
                    pq.push({dist[child] , child});
                }
            }
        }
        return dist;
    }
    void dfs(int node ,int  n , int mod , vector<pair<int,int>>adj[] , vector<int>&dist , vector<int>&dp , vector<int>&vis){
        vis[node] = 1;
        if(n == node)return;
        dp[node] = 0;
        for(auto [child, wt] : adj[node]){
            if(vis[child] == 0 ){
                if(dist[child] < dist[node]){
                    dfs(child, n, mod , adj , dist , dp , vis );
                    dp[node] = (dp[node]%mod +  dp[child]%mod)%mod;
                }
            }else{
                if(dist[child] < dist[node]){
                    dp[node] =(dp[node]%mod +  dp[child]%mod)%mod;
                }
            }
        }
        dp[node] = dp[node]%mod;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto i :edges){
            adj[i[0]].push_back({i[1] , i[2]});
            adj[i[1]].push_back({i[0] , i[2]});
        }
        vector<int> vis(n+1 , 0),  dp(n+1 , 0 ), dist = dikjstras(n , adj);
        dp[n] = 1;
        int mod = 1e9+7;
        dfs(1, n ,mod, adj , dist , dp , vis);
        return dp[1];
    }

};

```
</details>

<br> 



## [2039. The Time When the Network Becomes Idle](https://leetcode.com/problems/the-time-when-the-network-becomes-idle/) 

> There is a network of n servers, labeled from 0 to n - 1. You are given a 2D integer array edges, where edges[i] = [ui, vi] indicates there is a message channel between servers ui and vi, and they can pass any number of messages to each other directly in one second. You are also given a 0-indexed integer array patience of length n.
All servers are connected, i.e., a message can be passed from one server to any other server(s) directly or indirectly through the message channels.
The server labeled 0 is the master server. The rest are data servers. Each data server needs to send its message to the master server for processing and wait for a reply. Messages move between servers optimally, so every message takes the least amount of time to arrive at the master server. The master server will process all newly arrived messages instantly and send a reply to the originating server via the reversed path the message had gone through.
At the beginning of second 0, each data server sends its message to be processed. Starting from second 1, at the beginning of every second, each data server will check if it has received a reply to the message it sent (including any newly arrived replies) from the master server:
If it has not, it will resend the message periodically. The data server i will resend the message every patience[i] second(s), i.e., the data server i will resend the message if patience[i] second(s) have elapsed since the last time the message was sent from this server.
Otherwise, no more resending will occur from this server.
The network becomes idle when there are no messages passing between servers or arriving at servers.
Return the earliest second starting from which the network becomes idle.

<code >Logic</code>

```quote

1. find single source shorted path from 0 to all
2. find dist[]
3. we know total return time for one data is 2*d
4 case 1
2*d<=p

iss case m ye dusra message jaane ke pahle hi server idle ho jayega so iss case ka timing simple 2*d ho jayega ( jo 1st packet ke liye time lagega)

case 2

2*d>p

aab yaha bhi 2 case bante hai

ek to ye ho skta h jb humara pehla message dobara node pr pohache tb ye release krna chah raha ho kintu ye kr nh payega bcz humara reply aa gaya h iss samay (in simple 2*d is divisible by p)

Dusra ye ki jb humara pehla message ka reply aaye tb ye send krne ke state m na ho (in simple 2*d is not divisible by p)

First case :

pahle case ke liye total time = time taken for first message + time taken for last message
total time = 2d + (2d-p) (ye message tb nikla hoga jb first message current node se p distance durr hoga so jb first message pohacha hoga to ye last message source se p aage badh chuka hoga)
Hence,
total time = 4*d-p

second case:

Iss case ke liye total time = time taken for first message + time taken for last message
total time = 2d + (2d-2d%p) (ye message tb nikla hoga jb first message current node se 2d%p distance durr hoga so jb first message pohacha hoga to ye source se 2d%p aage badh chuka hoga)
Hence,
total time = 4d-2*d%p

Iske baad humne sare case ko dekh liya h aab hum coding start kr skte hai



```
[Code Link](./CodeGraph/05-when-the-network-become-idle.cpp)

<details><summary>Code</summary>

```cpp

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<int> dist(n) , adj[n] , vis(n,0);
        for(auto i :edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        vis[0] = 1;
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            for(auto i : adj[curr]){
                if(vis[i] == 0 ){
                    vis[i] = 1;
                    dist[i] = 1 + dist[curr];
                    q.push(i);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n ; i++){
             int d = dist[i];
             int temp = 2*d;
             //case when out period is smaller than total distance
             if(2*d > patience[i])
			 {
                 // is last msg is sending condition but we revive
                if((2*d)%patience[i]==0)
                    temp=4*d-patience[i];
                else
                // we already send last msg
                    temp=4*d-(2*d)%patience[i];   
            }
            ans = max(ans,temp);
        }
        return ans+1;
    }
};

```
</details>

<br> 

<!-- 

# Day 5

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

<br>  -->

