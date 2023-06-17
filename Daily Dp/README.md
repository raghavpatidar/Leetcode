# Daily DP problem June 2023 .

# Table of Content


- [Daily DP problem June 2023 .](#daily-dp-problem-june-2023-)
- [Table of Content](#table-of-content)
- [Day 1](#day-1)
  - [940. Distinct Subsequences II](#940-distinct-subsequences-ii)
  - [Dice Throws](#dice-throws)
- [Day 2](#day-2)
  - [486. Predict the Winner / Optimal Game Streatgy](#486-predict-the-winner--optimal-game-streatgy)
  - [221. Maximal Square](#221-maximal-square)
- [Day 3](#day-3)
  - [ColorFul Knapsack](#colorful-knapsack)
- [Day 4](#day-4)
  - [KMP Algo](#kmp-algo)
  - [1314. Matrix Block Sum](#1314-matrix-block-sum)
  - [1262. Greatest Sum Divisible by Three](#1262-greatest-sum-divisible-by-three)
- [Day 5](#day-5)
  - [494. Target Sum](#494-target-sum)
  - [646. Maximum Length of Pair Chain](#646-maximum-length-of-pair-chain)
- [Day 6](#day-6)
  - [688. Knight Probability in Chessboard](#688-knight-probability-in-chessboard)
- [Day 7](#day-7)
  - [115. Distinct Subsequences](#115-distinct-subsequences)
  - [132. Palindrome Partitioning II](#132-palindrome-partitioning-ii)
- [Day 8](#day-8)
  - [712. Minimum ASCII Delete Sum for Two Strings](#712-minimum-ascii-delete-sum-for-two-strings)
  - [174. Dungeon Game](#174-dungeon-game)
- [Day 9](#day-9)
  - [978. Longest Turbulent Subarray](#978-longest-turbulent-subarray)
  - [1039. Minimum Score Triangulation of Polygon](#1039-minimum-score-triangulation-of-polygon)
  - [1130. Minimum Cost Tree From Leaf Values](#1130-minimum-cost-tree-from-leaf-values)
  - [1049. Last Stone Weight II](#1049-last-stone-weight-ii)
  - [1218. Longest Arithmetic Subsequence of Given Difference](#1218-longest-arithmetic-subsequence-of-given-difference)
- [Day 11](#day-11)
  - [85. Maximal Rectangle](#85-maximal-rectangle)
  - [152. Maximum Product Subarray](#152-maximum-product-subarray)



# Day 1
## [940. Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii/description/) 

> Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo <code>109 + 7</code>. A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. i.e., <code>"ace</code>" is a subsequence of <code>"abcde</code>" while <code>"aec</code>" is not.

<code >Logic</code>




```quote
1. dp[i]  shows that total number of sequece till ith index but if we found repeating character then we have to remove it's all previous subsequence 
2. let say repeateIdx is  index where last time char i occur so we can remove it's all occurance before this such that dp[i] = dp[i]  - dp[repeateIdx - 1];
      Case 1 : if we found element which we don't found before
               simply add it's all subsequence to dp[i] = 2 * d[i-1];
      Case2 : found and repeated index 
             1 add all new sequence such that dp[i] = 2* dp[i-1];
             2 remove repeated subsequence count  dp[i] -= dp[repeatedIdx -1];

3. finally dp.back() will have our total distinxt subsequence 
```
[Code Link](./01-Distinct-subsequence.cpp)
<details><summary>code</summary>

```cpp
class Solution {
public:
    int distinctSubseqII(string s) {
        map<char, int> m ;
        vector<int>dp(s.size()+1);
        dp[0] = 1;
        int mod = 1e9 + 7;
        for(int i = 1; i <=s.size();i++){
            dp[i] = (2 * dp[i-1])%mod;
            if(m.find(s[i-1]) != m.end()){
                int repeateidx = m[s[i-1]]-1;
                dp[i] = (dp[i] - dp[repeateidx]);
                dp[i] %=mod;
            }
            m[s[i-1]] = i;
        }
        int n = s.size();
        dp[n]--;
        if(dp[n] < 0 )dp[n]+= mod;
        return dp[n] ;
    }
};
```
</details>

<br>

## [Dice Throws](https://www.codingninjas.com/codestudio/problems/dice-throws_799924?leftPanelTab=0) 
>You are given D dice, each having F faces numbered 1 to F, both inclusive. The task is to find the possible number of ways to roll the dice together such that the sum of face-up numbers equal the given target S. Return ans to modulo <code>1e9 + 7</code> .

<code >Logic</code>

```quote
1. Recursion    : Simple recursion with target sum approach our targeet is total sum and 
                  for each dice we have 1 to F option.
                  TC = O(2^N)  SC = O(N)

2. Memoization  : dp[i][j] -->number of ways  for ith dice have jth sum
                  Tc =O(N*N)   SC = O(N) + O(N*N)

3. Tabulation   : Remove Recursive Stack complexity
                  Tc =O(N*N)   SC = O(N*N)

4. Space Optimal: As we can see that we need only previous row dp[i-1] for our ith 
                  calculation so we can reomve our 2D dp and use prev  and curr 1D array
                  TC = O(N*N)  SC = O(2*N)
                      
```
[Code Link](./01-Dice-Throws.cpp)
<details><summary>code - Memoization</summary> 

```cpp
#include <bits/stdc++.h>

int solve(int idx  , int face , int target , vector<vector<int>>& dp , int mod ){
    
    if(idx == 0 and target == 0 )return 1;
    if(target == 0 || idx == 0 )return 0;
    if(dp[idx][target] != -1)return dp[idx][target];
    int cnt = 0;
    for(int j = 1 ; j<= face ; j++){
        if( target >= j ){
           cnt = ( cnt%mod +  solve(idx - 1 , face, target - j , dp, mod)%mod )%mod;
        }
    }
    return dp[idx][target] = cnt%mod;
}
int diceThrows(int d, int f, int s) {
    vector<vector<int>> dp(d +1 , vector<int>(s +1 , -1));
    int mod = 1e9+7;
    return solve(d , f , s  , dp , mod)%mod;
}
```
</details>
<details><summary>code - Tabulation</summary> 

```cpp
#include <bits/stdc++.h>
int diceThrows(int d, int f, int s) {
    vector<vector<int>> dp(d +1 , vector<int>(s +1 , -1));
    int mod = 1e9+7;
    for(int i = 0 ;i <= d ; i++)dp[i][0] = 0;
    for(int j = 0; j <= s ; j++ )dp[0][j] = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= d; i++) {
      for (int j = 1; j <= s; j++) {
            int cnt = 0;
            for(int k = 1 ; k<= f ; k++){
                if( j >= k ){
                cnt = ( cnt%mod +  dp[i - 1][j - k] )%mod;
                }
            }
            dp[i][j] = cnt%mod;
      }
    }
    return dp[d][s]%mod;
}
```
</details>
<details><summary>code- Space Optimization</summary> 

```cpp
int diceThrows(int d, int f, int s) {
    int mod = 1e9+7;
    vector<int> prev(s+1 , 0) , curr(s+1 , 0);
    for(int j = 0; j <= s ; j++ )prev[j] = 0;
    prev[0] = 1;
    for (int i = 1; i <= d; i++) {
        curr[0] = 0;
      for (int j = 1; j <= s; j++) {
            int cnt = 0;
            for(int k = 1 ; k<= f ; k++){
                if( j >= k ){
                cnt = ( cnt%mod +  prev[j - k] )%mod;
                }
            }
          curr[j] = cnt%mod;
      }
      prev = curr;
    }
    return prev[s]%mod;   
}
```
</details>
<br>

# Day 2
## [486. Predict the Winner / Optimal Game Streatgy](https://leetcode.com/problems/predict-the-winner/description/) 
>You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array. Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

<code >Logic</code>

```quote
This is MiniMax Logic  we can max of min in our DP state Generally used in Game theory
(i,j) is the position from player 1 can pick
Case1:  pick from start (ith)
            then second player has two options 
                Condition1: he can pick from start which is i+1 so player 1 have left with (i+2,j) for next move
                Condition2 he can pick from end which is j-1 so plaayer 1 have open for first is (i+1,j-1) for next move
            now as both are playing optimally second player will choose max from 1 and 2 so first player have got min of both condition 
            such that startPick = min(Condition1 , Condition2) + arr[i] (as start value is picked)
Case2:  pick from end (jth)
            then second player has two options 
                Condition1: he can pick from start which is i+1 so player 1 have (i+2,j) for next move
                Condition2: he can pick from end which is j-1 so plaayer 1 have open for first is (i+1,j-1) for next move
            now as both are playing optimally second player will choose max from 1 and 2 so first player have got min of both condition 
            endPick = min(Condition1 , Condition2) + arr[j] (as end value is picked)

now our player 1 can choose max of both case such that CurrSum = Max(Case1 , Case2) == Max(startPick , endPick);
```
[Code Link](./02-Optimal-Gram-Streatgy.cpp)
<details><summary>code</summary>

```cpp

class Solution {
public:
    int solve(int i , int j , vector<int>& nums , vector<vector<int>>&dp){{
        if(i > j)return 0;
        if(i == j )return nums[i];

        if(dp[i][j] != -1)return dp[i][j];

        int startPick = nums[i] + min(solve(i+2 , j , nums, dp) ,solve( i+1,j-1,nums,dp));
        int endPick = nums[j] + min(solve(i , j-2 , nums ,dp) , solve(i+1 , j-1 , nums , dp));

        int currSum = max(startPick , endPick);
        return dp[i][j] = currSum;

    }}
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int totalSum = 0;
        for(auto i :nums)totalSum += i;
        int suma = solve(0 , n-1 , nums, dp );
        int sumb = totalSum - suma;
        cout<<suma<<" " <<sumb<<endl;
        return suma >= sumb;
    }
};
```
</details>
<br> 



## [221. Maximal Square](https://leetcode.com/problems/maximal-square/description/) 

> Given an m x n binary matrix filled with 0's and 1's, find the largest <code>square</code>  containing only 1's and return its area.

<code >Logic</code>

```quote
Approach 1 : dp[i][j] --> max length of square at i,j and stores it length
        case 1: i ==0 then we are at first row so max length is one if matrix[0][j] = 1 i.e dp[0][j]= matrix[0][j]
        case 2: j ==0 then we are at first col so max length is one if matrix[i][0] = 1 i.e dp[i][j]= matrix[i][0]
        case 3: matrix[i][j] = 0  means current index we don't have any square i.e dp[i][j] = 0
        case 4: matrix[i][j] = 1  measn we can have square of and it's max len is Min( dp[i-1][j-1] , dp[i-1][j-1] , dp[i][j-1]) +1
                such that it's min of it's uper square , previous back square od digonal left up
        we can take max of all dp[i][j] and return it's area as square of side*side

Approach 2 : Think of  Aream of Histrogram we can think each layers as histroger of top of it
             dp[i][j] histogram at ith row and jth value 
             dp[i] each row 
             if matrix[i][j] = 1  then dp[i][j]= dp[i-1][j]
             else dp[i][j] = 0
             ans = max(ans , AreaHitogram(dp[i]));
```
[Code Link](./02-Maximal-Square.cpp)
<details><summary>Approach 1 code</summary>

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size() , ans = 0;
        vector<vector<int>> dp(n , vector<int>(m, 0));
        for(int i= 0; i < n ; i++){
            for(int j= 0; j < m ; j++){
                if(i == 0 || j ==0 || matrix[i][j] =='0') dp[i][j] = matrix[i][j] -'0';
                else {
                   dp[i][j] = min({dp[i-1][j-1] , dp[i][j-1] , dp[i-1][j]})+1;
                }
                ans = max(ans , dp[i][j]);
            }
        }
        return ans*ans;

    }
};
```
</details>
<details><summary>Approach 2 code</summary>

```cpp
class Solution {
public:
    vector<int> nsl(vector<int>v){
        stack<int>st;
        vector<int> ans;
        for(int i = 0; i < v.size() ; i++){
            if(st.size()>0){
                while(st.size()>0 and v[st.top()] >= v[i])st.pop();
                if(st.size() == 0)ans.push_back(-1);
                else ans.push_back(st.top());
            }else{
                ans.push_back(-1);
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nsr(vector<int>v){
        stack<int>st;
        vector<int> ans;
        int n = v.size();
        for(int i = v.size()-1; i >= 0 ; i--){
            if(st.size()>0){
                while(st.size()>0 and v[st.top()] >= v[i])st.pop();
                if(st.size() == 0)ans.push_back(n);
                else ans.push_back(st.top());
            }else{
                ans.push_back(n);
            }
            st.push(i);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }

    int maxHistogram(vector<int> v){
        vector<int>left = nsl(v);
        vector<int>right = nsr(v);
        int ans = 0;
        for(int i = 0; i < v.size() ; i++){
            int w = (right[i] - left[i] - 1 );
            int h =v[i];
            int area = min(h , w) * min(h , w);
            ans = max(ans , area);
        }
        return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n , vector<int>(m , 0));
        for(int j = 0; j < m ; j++)dp[0][j] = matrix[0][j] - '0';
        int ans = maxHistogram(dp[0]);
        for(int i = 1; i < n ; i++){
            for(int j = 0; j < m ;j++){
                if(matrix[i][j] == '0' )dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] +1;
            }
            ans = max(ans ,maxHistogram(dp[i]));
        }
        return ans;
    }
};
```
</details>
<br> 


# Day 3
## [ColorFul Knapsack](https://www.codingninjas.com/codestudio/problems/colorful-knapsack_630415) 

> You are given 'N' stones labeled from 1 to 'N'. The 'i-th' stone has the weight W[i]. There are 'M' colors labeled by integers from 1 to 'M'. The 'i-th' stone has the color C[i] which is an integer between 1 to 'M', both inclusive. 
> You have been required to fill a Knapsack with these stones. The Knapsack can hold a total weight of 'X'.
> You are required to select exactly 'M' stones; one of each color. The sum of the weights of the stones must not exceed 'X'. Since you paid a premium for a Knapsack with capacity 'X', you are required to fill the Knapsack as much as possible.
> Write a program to calculate the best way to fill the Knapsack - that is, the unused capacity should be minimized.

<code >Logic</code>

```quote

we can map each color with all weights with same color
eg : use Map<int, vector> mp

8 3 13
2 3 4 2 4 5 2 3
1 1 1 2 2 2 3 3

mapping
col--> list of weight is same color
1 -> [2 3 4]
2 -> [2 4 5]
3 -> [2 3]

now we can think of Dynamic Programming
for each color we we have only one choice to pick it and but which one to be picked it may differ
so calculate max answer will give us minimum unused capacity

```
[Code Link](./03-colorful-Knapsack.cpp)
<details><summary>code</summary>

```cpp

#include <bits/stdc++.h>

int cnt = 1e9;
int solve(int idx , int target , int m ,  map<int, vector<int>>&mp
,map<pair<int,int> , int>&dp ){
    //base
    if(idx == m){
         
         cnt = min(cnt , target);
        return target;
    }
    if(target <= 0 ){
        return 1e9;
    }
    //memo
    if(dp.find({idx , target})!= dp.end())return dp[{idx,target}];
    int curr = 1e9;

    // using all only once
    for(auto j : mp[idx+1]){
      if (target >= j) {
        int pick = j + solve(idx + 1, target - j , m ,mp , dp );
        curr = min(curr , pick);
      }
    }
    return dp[{idx , target}] = curr;
    
}

int colorfulKnapsack(int w[], int c[], int n, int m, int x)
{
    map<int, vector<int>>mp;
    map<pair<int,int> , int>dp;
    for(int i =0 ; i < n ; i++){
        mp[c[i]].push_back(w[i]);
    }
    int ans = solve(0 , x , m , mp , dp);
    return cnt==1e9 ? -1 : cnt;
}

```
</details>
<br> 

# Day 4

## [KMP Algo](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) 

> Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

<code >Logic</code>

```quote

1. Build LPS array
2. LPS array is longest prefic suffix array
3. Building LSP array --
   use two pointer prevLps = 0 , i = 1;
   if needle value is same then increase lsp[i] to prevLsp +1 and prevLps++ , i++
   now if not equale move to prevLsp until same char found of j = 0
   if j become move ith pointer with current lps = 0;

4. using lsp array to find pattern matching 
5. use two pointer i for haystack and j for needle 
   if char is i,j equal move forward 
   otherwise move backward unitl we find lsp such that current i equal to lsp[j-1] or j become 0

 ```
[Code Link](./04-KMP-algo.cpp)

<details><summary>code</summary>

```cpp

class Solution {
public:
    int strStr(string haystack, string needle) {
        //creating lps array
        int n = haystack.size();
        int m = needle.size();
        vector<int>lps(m);
        //calculating lps
        int prevLps = 0 , i = 1;
        while(i < m ){
            //is equal add 1 and move forward
            if(needle[i] == needle[prevLps]){
                lps[i] = prevLps+1;
                i++;
                prevLps++;
            }else{
                if(prevLps == 0){
                    // if first index move forrad base case
                    lps[i] = 0;
                    i++;
                }else{
                    //move backwords till not getting matching char
                    prevLps = lps[prevLps-1];
                }
            }
        }

        //KMP algo
         i = 0 ;
         int j = 0;
        while(i < n){
            //match
            if(needle[j] == haystack[i]){
                i++ , j++;
            }else{
                //not match
                if(j == 0 ){
                    //base case if we are at first position and not
                    //not match move forward
                    i++;
                }else{
                    //move to last lps
                    j= lps[j-1];
                }
            }

            //if we god our string match return
            if(j == m){
                // return starting indx of i pointer which is i - m
                return i - m;
            }
        }
        

        return -1;

    }
};

```
</details>
<br> 



## [1314. Matrix Block Sum](https://leetcode.com/problems/matrix-block-sum/) 

> Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
> - i - k <= r <= i + k,
> - j - k <= c <= j + k, and
> - (r, c) is a valid position in the matrix.

<code >Logic</code>

```quote

1. Fisrt calculate dp sum
2. for each i,j find it's lower bound and upper bound such that kth conner values 
3. of total sum of rectangle we can use dp[i][j] - dp[i-1][j] - dp[i][j-1] + dp[i-1][j-1]
4 add because it get subtracted 2 times in a row

```
[Code Link](./04-matrix-block-sum.cpp)
<details><summary>code</summary>

```cpp

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size() , m = mat[0].size();
        vector<vector<int>>dp( n+1 , vector<int>(m+1 , 0));
        for(int  i = 1; i <= n  ;i++){
            for(int j = 1; j <= m ; j++){
                 dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i-1][j-1];
            }
        }
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++)
            {
                int x1 = max(0, i-k);
                int y1 = max(0, j-k);
                int x2 = min(n-1, i+k);
                int y2 = min(m-1, j+k);
                x1++ , y1++, x2++, y2++;
                 mat[i][j] = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
            }
        }
        return mat;
    }
};


```
</details>
<br> 



## [1262. Greatest Sum Divisible by Three](https://leetcode.com/problems/greatest-sum-divisible-by-three/) 

> Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

<code >Logic</code>

```quote

1. Think of Dp state with two value current index and mod dp[idx][mod]
2. do simple recurrsion
3. convert into modulo tabulation 

```
[Code Link]()
<details><summary>code</summary>

```cpp

class Solution {
public:
    int solve(int idx , int mod , vector<int>&nums , vector<vector<int>>dp){
        if(idx == 0){
            if(mod == 0)return 0;
            else return -1e9;
        }

        if(dp[idx][mod] != -1)return dp[idx][mod];


        int pick = nums[idx-1] + solve(idx- 1 , (nums[idx-1]+mod)%3 , nums , dp);
        int notPick = solve(idx -1 , mod , nums , dp);
        return dp[idx][mod] =  max(pick , notPick);
    }
     
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1 , vector<int>(3 , -1e9));
        dp[0][0] = 0;
        dp[0][1] = -1e9;
        dp[0][2] = -1e9;
        for(int i = 1; i <= nums.size() ; i++){
            for(int j = 2 ;j >= 0 ; j--){
                int pick = nums[i-1] + dp[i- 1 ][ (nums[i-1]+j)%3 ];
                int notPick = dp[i -1][j];
                 dp[i][j] =  max(pick , notPick);
            }
        }
        return dp[nums.size()][0];
        // return solve(nums.size() , 0 , nums , dp);
    }
};


```
</details>
<br> 


# Day 5
## [494. Target Sum](https://leetcode.com/problems/target-sum/description/) 

> You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
> - For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

<code >Logic</code>

```quote

1. seperate positive and negative
2. so s1 +ve and s2 -ve sum
3. s1 - (abs(s2)) = target
4. s1 + s2 = TotSum
5. by adding above euqations we get 
6. s1 = (target + TotSum)/2;
7. so if s1 is not integer then answer is  0
8. otherwise we just need to count so new target which is s1 in our array

```
[Code Link](./05-target-sum.cpp)
<details><summary>code</summary>

```cpp

class Solution {
public:
    int solve(int i, int target, vector<int>&nums,vector<vector<int>>&dp){
        //base case
        if(i<0)
            return target==0;
        
        //check the cache
        if(dp[i][target]!=-1)
            return dp[i][target];
            
        int pick=0,notpick=0;
        notpick = solve(i-1,target,nums,dp);
        if(target>=nums[i])
            pick = solve(i-1,target-nums[i],nums,dp);
        
        return  dp[i][target] = pick + notpick;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total_sum=0;
        for(int i=0;i<n;i++)
            total_sum+=nums[i];
        int T= target + total_sum;
        if(T%2 || T<0)
            return 0;
        vector<vector<int>>dp(n,vector<int>(T/2+1,-1));
        return solve(n-1,T/2,nums,dp);
    }
};


```
</details>
<br> 

## [646. Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/) 

> You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
Return the length longest chain which can be formed.
You do not need to use up all the given intervals. You can select pairs in any order.

 

<code >Logic</code>

```quote

1. Knapscak logic
2. pick if condition satisfy otherwise not pick
3. retrun max 

```
[Code Link](./05-maxinum-len-pair-chain.cpp)
<details><summary>code</summary>

```cpp


class Solution {
public:
    int solve(int idx, int previdx, vector<vector<int>>& pairs, vector<vector<int>>& dp) {
        if (idx == pairs.size()) {
            return 0;
        }
        if (dp[idx][previdx + 1] != -1)return dp[idx][previdx + 1];

        int notPick = solve(idx + 1, previdx, pairs, dp);
        int pick = 0;
        if (previdx == -1 || pairs[idx][0] > pairs[previdx][1]) {
            pick = 1 + solve(idx + 1, idx, pairs, dp);
        }
        return dp[idx][previdx + 1] = max(pick, notPick);
    }

    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] < b[0])return true;
        if (a[0] > b[0])return false;
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        sort(pairs.begin(), pairs.end(), comp);
        int ans = solve(0, -1, pairs, dp);
        return ans;

    }
};


```
</details>
<br> 


# Day 6
## [688. Knight Probability in Chessboard](https://leetcode.com/problems/knight-probability-in-chessboard/) 

> On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.

<code >Logic</code>

```quote

1. dp[row][col][k] --> row , column , k moves
2. if we are at index where row or col outofnound return 0
3. if we got k ==0 return 1
4. calculate for all 6 directions and take probability such that 1/8

```
[Code Link](./06-knight-probability.cpp)
<details><summary>code</summary>

```cpp

class Solution {
public:
    // int dx[8] = {-2 , -2 ,-1 , -1 , 1 , 1 , 2 , 2};
    // int dy[8] = {1 , -1  ,2  , -2 , 2 , -2 , 1 , -1};
    vector<int>dx={-2,-2,-1,-1,1,1,2,2},dy={-1,1,-2,2,-2,2,1,-1};

    double solve(int  r , int c , int k , int n , vector<vector<vector<double>>>&dp ){
        if(r < 0 || c < 0 || r >= n || c >= n )return 0.0;
        if(k == 0)return 1.0;
        if(dp[r][c][k] != -1)return dp[r][c][k];
        double cnt = 0;
        for(int i = 0 ; i < 8; i++){
            cnt += ( solve(r +  dx[i] , c +  dy[i] , k - 1 , n, dp));
        }
        cnt = cnt/8;
        return dp[r][c][k] = cnt;
        return cnt;
    }
    double knightProbability(int n, int k, int row, int column) {
         vector<vector<vector<double>>> dp( n +1, vector<vector<double>>( n+1 , vector<double>(k+1 , -1)));
         return solve(row , column , k , n , dp);
    }
};


```
</details>
<br> 



# Day 7
## [115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/s) 

> Given two strings s and t, return the number of distinct 
subsequences
 of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

 

<code >Logic</code>

```quote

1. String matching DP pattern
2. Think like moving from back and we have two option
3. IF it is same then we can move forward in both strings i-1 , j-1
4. else we can not take form our first string s such that i-1 , j 
5. Base Case --> if we reach to end of second string mean we find pattern return true
5. if we reach to end of first string and not second then we finish all our string and not find patter yet so return false
6. return sum of all answer as we need count 

```
[Code Link](./07-Distinct-sequences.cpp)

<details><summary>code</summary>

```cpp

class Solution {
public: 
    int solve(int i  , int  j , string &s , string&t , vector<vector<int>>&dp){
        if(j == 0 )return 1 ;
        if(i == 0 )return 0;

        if(dp[i][j] != -1)return dp[i][j];

        //same
        int same = 0;
        if(s[i-1] == t[j-1]){
            same = solve(i-1 , j-1 , s , t , dp);
        }
        int notSame  = solve(i-1 , j , s , t , dp );

        return dp[i][j] =  same + notSame;
    }
    int numDistinct(string s, string t) {
        int n  = s.size(), m = t.size();
        vector<vector<int>>dp(n+1 , vector<int> (m+1 ,-1));
        return solve(n , m , s , t , dp);
    }
};

```
</details>
<br> 





## [132. Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/) 

> Given a string s, partition s such that every 
substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

<code >Logic</code>

```quote

1. Think Of MCM pattern
2. [aaabbc] from start we will start puttion our partition till end 
   such that start from i 
3. Base -> if i>=0 we  can return 0 we don't need more cuts
4. if(our current i --> to --> n) have palindrom so we don't need more cuts
5. k range [i +1 , n-1]
6. if [i,k] is plaindrom then we can add call recursion on this

```
[Code Link](./07-Palindrome-partitioning-II.cpp)

<details><summary>code</summary>

```cpp

class Solution {
public:
    bool checkPalindrome(int i , int j , string &s){
        while(i  <= j ){
            if(s[i] != s[j])return false;
            i++ , j--;
        }
        return true;
    }
    int solve(int i  , string &s  , vector<int>&dp){
        
        if(i>= s.size() or checkPalindrome(i, s.size() -1 , s)) return 0;
        int mini = 1e9;
        if(dp[i] != -1)return dp[i];
        
        for(int k = i ; k < s.size() ; k++){
            if(checkPalindrome(i,k,s)){
                int temp = 1 + solve(k+1 , s , dp);
                mini = min(temp , mini);
            }
        }
        return dp[i] =  mini;

    }
    int minCut(string s) {
        if(s.size() == 0 )return 0;
        vector<int>dp(s.size()+1 , -1);
        return solve(0  , s , dp);
    }
  
};

```
</details>

<br> 




# Day 8
## [712. Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/) 

> Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal

<code >Logic</code>

```quote

1. Base Case - if first string become empty and we left with second so we need to
   deleted all from second such that i==0 return sumPref(till j) same of second string also
2. now if we got both same value we don't need to delete this just move forward [i-1,j-1]
3. if we are at different we can delete any one of them so try both cases [i-1,j] and [i,j-1]
```
[Code Link](./08-Minimum-ASCII-sum-delete.cpp)

<details><summary>code</summary>

```cpp

class Solution {
public:
    int solve(int  i , int j , string &s , string&t  ,vector<vector<int>>&dp ){
        if(i == 0 and j== 0)return 0;
        if(i == 0 )return t[j-1] + solve(i , j- 1 , s , t , dp);
        if(j == 0 )return s[i-1] + solve(i-1 , j , s , t , dp);
       
        
        if(dp[i][j] != -1 )return dp[i][j];

        int same = 1e9;
        if(s[i-1] == t[j-1]){
            return solve(i-1 , j- 1 ,s , t , dp);
        }
        int notSameMoveFirst = s[i-1] + solve(i-1 , j , s , t , dp);
        int notSameMoveSecond = t[j-1] + solve(i , j-1 , s , t, dp);

        return dp[i][j] =  min( notSameMoveFirst , notSameMoveSecond); 
    }
    int minimumDeleteSum(string s1, string s2) {
       int n = s1.size() , m = s2.size();
       vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1) );
       return  solve(n , m , s1 , s2 , dp);
       
    }
};

```
</details>

<br> 

## [174. Dungeon Game](https://leetcode.com/problems/dungeon-game/submissions/969903884/) 

> The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.
The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).
To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
Return the knight's minimum initial health so that he can rescue the princess.
Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned

- [Best Explanation of DP Approach ](https://leetcode.com/problems/dungeon-game/solutions/745340/post-dedicated-to-beginners-of-dp-or-have-no-clue-how-to-start/)

<code >Logic</code>

```quote

1. Think of Recursion 
2. like what is the Base Case
3. Think like you have 1D array means last row
4. so for this if we have mat[i][j] <= we need to 1 + (- mat[i][j])
5. is at anypoint our helath is become negative we need minimum 1
6. calculation taking min of left and right health 
7. Check out REcurssion code for more understanding 
```
[Code Link](./08-Dungeon-games.cpp)

<details><summary>Recursion + Memoization</summary>

```cpp

 class Solution {
public: 
    int solve(int  i ,int  j , int n , int m , vector<vector<int>>& dungeon , vector<vector<int>>&dp){

        //Base Case
        if(i == n || j == m)return 1e9;
        if(i == n-1 and j == m - 1){
            return dungeon[i][j] < 0 ? 1 - dungeon[i][j] : 1;
        }

        if(dp[i][j] != -1)return dp[i][j];

        int left = solve(i , j+1 , n , m , dungeon , dp);
        int right = solve(i+1 , j , n , m , dungeon , dp);

        int minHealth = min(left , right) - dungeon[i][j];

        return dp[i][j] =  minHealth <= 0 ? 1 : minHealth;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n  , vector<int>(m , -1));
        return solve(0 , 0, n , m , dungeon , dp);
    }
};

```
</details>

<details><summary>Tabulation</summary>

```cpp

class Solution {
public: 
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n +1 , vector<int>(m+1 , 1e9));
        for(int i = n -1 ; i>= 0; i--){
            for(int j = m - 1;  j>= 0 ; j--){
                if(i == n-1 and j == m-1) dp[i][j] = dungeon[i][j] < 0 ? 1 - dungeon[i][j] : 1;
                else{
                    int left = dp[i][j+1];
                    int right = dp[i+1][j];
                    int minHealth = min(left , right) - dungeon[i][j];
                    dp[i][j] =  minHealth <= 0 ? 1 : minHealth;
                }
            }
        }
        return dp[0][0];
    }
};

```
</details>

<details><summary>Space Optimized</summary>

```cpp

class Solution {
public: 
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        // vector<vector<int>> dp(n +1 , vector<int>(m+1 , 1e9));
        vector<int>prev(m+1 , 1e9) , curr(m+1 , 1e9);
        for(int i = n -1 ; i>= 0; i--){
            for(int j = m - 1;  j>= 0 ; j--){
                if(i == n-1 and j == m-1) curr[j] = dungeon[i][j] < 0 ? 1 - dungeon[i][j] : 1;
                else{
                    int left = curr[j+1];
                    int right = prev[j];
                    int minHealth = min(left , right) - dungeon[i][j];
                   curr[j] =  minHealth <= 0 ? 1 : minHealth;
                }
                prev = curr;
            }
        }
        return prev[0];
    }
};

```
</details>

<br> 
<br> 




# Day 9
## [978. Longest Turbulent Subarray](https://leetcode.com/problems/longest-turbulent-subarray/) 

>  Given an integer array arr, return the length of a maximum size turbulent subarray of arr.
> A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
> More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:
> - For i <= k < j:
>   - arr[k] > arr[k + 1] when k is odd, and
>   - arr[k] < arr[k + 1] when k is even.
> - Or, for i <= k < j:
>   - arr[k] > arr[k + 1] when k is even, and
>   - arr[k] < arr[k + 1] when k is odd.
 

<code >Logic</code>

```quote

1. Think of Lis Pattern in dp
2. we can use another dp state which is prev tell we have to pick greater or smaller on current index
3. dp[idx][prev][]

```
[Code Link](./09-longest-Turbulent-Subarray.cpp)

<details><summary>code</summary>

```cpp

class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&v,int i , bool t ,int prev)
    {
        if(i==v.size())
          return 0;
        if(dp[prev][t]!=-1)
            return dp[prev][t];
        if(prev==0)
        {
    return dp[prev][t]=max({1+solve(v,i+1,0,i+1),1+solve(v,i+1,1,i+1),solve(v,i+1,t,prev)});
        }
        else if(t==0)
        {
            if(v[i]<v[prev-1])
                return dp[prev][t]=1+solve(v,i+1,1,i+1);
        }
        else
        {
            if(v[i]>v[prev-1])
                return dp[prev][t]=1+solve(v,i+1,0,i+1);
        }
         return dp[prev][t]=0;
    }
    int maxTurbulenceSize(vector<int>& arr)
    {
       int n=arr.size();
        dp.resize(n+1,vector<int>(3,-1));
       return solve(arr,0,0,0);                     
    }
};

```
</details>

<br> 

 
## [1039. Minimum Score Triangulation of Polygon](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/) 

> - You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).
You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.
Return the smallest possible total score that you can achieve with some triangulation of the polygon.

<code >Logic</code>

```python

1. Think of MCM pattern
2. WE can Fix i, j are take max from subary [i,k] and [k+1 , j]
3. and current score is arr[i-1]*arr[k]*arr[j]

4. approach - > 
5. Base Case
6. Range Block [i to j]
7. K Range [k=i to k=j-1] 
8. find Score and call sub prblems 
9. return mini of all possible cases


```
[Code Link](./09-Minimum-Score-Tringulation-ofPolygon.cpp)

<details><summary>code</summary>

```cpp

class Solution {
public:
    int solve(int i , int j , vector<int>&arr , vector<vector<int>>&dp){
        if(i >= j )return 0;

        if(dp[i][j] != -1)return dp[i][j];

        int mini = 1e9;
        for(int k = i; k <= j -1; k++){
            int temp = arr[i-1]*arr[k]*arr[j] + solve(i , k , arr , dp) + solve(k+1 , j , arr,  dp );
            mini = min(mini , temp);
        }
        return dp[i][j] =  mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n , vector<int>(n, -1));
        return solve(1 , n-1 , values, dp);
    }
};


```
</details>

<br> 

 

## [1130. Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/) 

> - Given an array arr of positive integers, consider all binary trees such that:

> - Each node has either 0 or 2 children;
> - The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
> - The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
> - Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.
> - A node is a leaf if and only if it has zero children.

<code >Logic</code>

```quote

1. Think of MCM pattern
2. Solve for ith value 
3. Think of base case if i == j 
4. what is return type or our value we need to trak two thing current minimum sum and minimum value in it's array

```
[Code Link](./10-minimum-cost-tree-from-leaf-values.cpp)

<details><summary>code</summary>

```cpp


class Solution {
public:
    pair<int, int> solve(int i ,int j  , vector<int> &arr  , vector<vector<pair<int,int>>> &dp){
           if(i == j )return {0 , arr[i]};
           if(i > j )return {1e9 , 1};
           if(dp[i][j] != make_pair(-1 , -1))return dp[i][j];
           pair<int, int> mini = {1e9 ,1 };
           for(int k = i  ; k < j; k++){
               auto left = solve(i , k , arr , dp);
               auto right = solve(k+1 , j, arr , dp);
               pair<int, int> temp = {left.second * right.second , max(left.second , right.second)};
               temp.first = temp.first +  left.first + right.first;
               if(temp.first < mini.first){
                   mini = temp;
               }
           }
           return dp[i][j] =  mini;


    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<pair<int,int>>> dp(n , vector<pair<int,int>>(n , {-1 , -1}));
        auto ans = solve(0 , arr.size()-1 , arr , dp);
        return ans.first;

    } 
};

```
</details>

<br> 


## [1049. Last Stone Weight II](https://leetcode.com/problems/last-stone-weight-ii/) 

> You are given an array of integers stones where stones[i] is the weight of the ith stone.

> We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:
> If x == y, both stones are destroyed, and
> If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
> At the end of the game, there is at most one stone left.
> Return the smallest possible weight of the left stone. If there are no stones left, return 0.

<code >Logic</code>

```quote

or three number a1, a2, a3, according to the order of our choice,
there are 8-2=6 different cases:
 
- a1 - (a2 - a3) = a1 - a2 + a3
- (a2 - a3) - a1 = -a1 + a2 - a3
- a1 - (a3 - a2) = a1 + a2 - a3
- (a3 - a2) - a1 = -a1 - a2 + a3
- a2 - (a1 - a3) = -a1 + a2 + a3
- (a1 - a3) - a2 = a1 - a2 - a3
- a2 - (a3 - a1) = a1 + a2 - a3 same as case 3
- (a3 - a1) - a2 = -a1 - a2 + a3 same as case 4
- a3 - (a1 - a2) = -a1 + a2 + a3 same as case 5
- (a1 - a2) - a3 = a1 - a2 - a3 same as case 6
- a3 - (a2 - a1) = a1 - a2 + a3 same as case 1
- (a2 - a1) - a3 = -a1 + a2 - a3 same as case 2
- for each number, we can add '+' or '-' before it. there are totally 2^3 = 8 cases
- but it cannot be all positive or all negtive, so it will decrease 2 cases.
 
the answer is choose some numbers to be positive, others negtive.
assume psum is the sum of positive number.
Our goal is to minimize psum - (sum(stones)-psum) = 2*psum - sum(stones)


So,
  // p-->positive , n--> negative
        // p + n = S
        // p - n = mi
        // 2P - S = mi
        // all possible positive sum


        we just need to find all possible P such that we can minimise 2P-S = mi
        and keep then positve they can be negation also
        Where P is subset which we are taking as postive sum 



```
[Code Link](./10-last-Stone-Weight-II.cpp)

<details><summary>code</summary>

```cpp

class Solution {
public:
    void allPositiveSum(int idx , vector<int>&stones , int curr , set<int>&ans ,vector<vector<int>> &dp){
        if(idx == 0 ){
            ans.insert(curr);
            return;
        }
        if(dp[idx][curr] != -1 )return;
        allPositiveSum(idx - 1 , stones , curr , ans , dp);
        allPositiveSum(idx -1 , stones, curr + stones[idx-1] , ans , dp);

        dp[idx][curr] = 1;
    }
    int lastStoneWeightII(vector<int>& stones) {
        // p-->positive , n--> negative
        // p + n = S
        // p - n = mi
        // 2P - S = mi
        // all possible positive sum
        int n = stones.size();
        set<int> ans;
        vector<vector<int>> dp (n+1 , vector<int> (3005 , -1));
        allPositiveSum(n , stones , 0 , ans , dp);
        cout<<ans.size()<<endl;
        vector<int> pos;
        int s = accumulate(stones.begin() , stones.end() , 0LL);
        for(auto i : ans){
                pos.push_back(abs(2*i - s));

        }
        
        return *min_element(pos.begin() , pos.end());
    }
};

```
</details>

<br> 



## [1218. Longest Arithmetic Subsequence of Given Difference](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/) 

> Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.
> A subsequence is a sequence that can be derived from arr by deleting some or no elements without changing the order of the remaining elements.

<code >Logic</code>

```quote

1. At cuureent idx check we have arr[i] - diff element before if yes then
2. add it's previous sequence count such that dp[arr[i]] =  dp[arr[i]-diff];
3. else add 1 to dp[arr[i]] = 1;

```
[Code Link](./10-longest-arithmitic-subsequece.cpp)

<details><summary>code</summary>

```cpp

class Solution {
public:
    
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        map<int , int> m ;
        
        int ans = 0;
        for(int i = 0; i < n ; i++){
            int x = arr[i] - difference;
            if(m.count(x)){
                m[arr[i]] =1 + m[x];
            }else{
                m[arr[i]] = 1;   
            }
            ans = max(ans , m[arr[i]]);
        }
        return ans;
    }
};

```
</details>

<br> 
<br> 



# Day 11
## [85. Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/description/) 

> Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

<code >Logic</code>

```quote

1. Think of finding maximum area of hostogram
2. for each row we can take if 1 from bottom to up as histogram our 1*(no of 1)
3. now how question become very simple to find max from all n histrogram array
```

[Code Link](./11-maximal-rectangle.cpp)

<details><summary>code</summary>

```cpp
class Solution {
public:
    vector<int> nsl(vector<int>v){
        stack<int>st;
        vector<int> ans;
        for(int i = 0; i < v.size() ; i++){
            if(st.size()>0){
                while(st.size()>0 and v[st.top()] >= v[i])st.pop();
                if(st.size() == 0)ans.push_back(-1);
                else ans.push_back(st.top());
            }else{
                ans.push_back(-1);
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nsr(vector<int>v){
        stack<int>st;
        vector<int> ans;
        int n = v.size();
        for(int i = v.size()-1; i >= 0 ; i--){
            if(st.size()>0){
                while(st.size()>0 and v[st.top()] >= v[i])st.pop();
                if(st.size() == 0)ans.push_back(n);
                else ans.push_back(st.top());
            }else{
                ans.push_back(n);
            }
            st.push(i);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }

    int maxHistogram(vector<int> v){
        vector<int>left = nsl(v);
        vector<int>right = nsr(v);
        int ans = 0;
        for(int i = 0; i < v.size() ; i++){
            int w = (right[i] - left[i] - 1 );
            int h =v[i];
            int area = (h*w);
            ans = max(ans , area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m , 0 ) ;
        for(int j = 0; j < m ; j++)prev[j] = matrix[0][j] - '0';
        int ans = maxHistogram(prev);
        for(int i = 1; i < n ; i++){
            for(int j = 0; j < m ;j++){
                if(matrix[i][j] == '0' )prev[j] = 0;
                else prev[j] = prev[j] +1;
            }
            ans = max(ans ,maxHistogram(prev));
            // prev = curr;
        }
        return ans;
        
    }
};
```
</details>

<br> 





## [152. Maximum Product Subarray](./11-product-subarray.cpp) 

> Given an integer array nums, find a 
subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.

 

<code >Logic</code>

```quote

1. Using Dynamic programming approach:
     1. If we will pick an number we can add it's product
     2. if not we will start fresh from current number as base
     3. need two state prevProduct and idx
     4. Base condtion is simple if idx == 0 return prevProdcut;
     5. Recurssion memeoization

2. Using Obersivation :
    a) -> all are posivive 
    b) -> positive and even negative
    c) -> postive and odd negative [1 , 2 ,-1 ,3 , 4]
          We can think that we need max pre before -1 or max suffix after -1
    d) -> if there is zero we can start fresh from there
                                    
```
[Code Link](./11-product-subarray.cpp)

<details><summary>code</summary>

```cpp

class Solution {
public:
    int solve(int idx,int prev , vector<int>&nums , map<pair<int,int>,int>&dp){
         if(idx == 0)return prev;

         if(dp.count({idx , prev}))return dp[{idx , prev}];

         if(prev == -1e9){
                int pick =   solve(idx -1 , nums[idx -1], nums ,  dp);
                int notPick = solve(idx -1 , nums[idx-1] , nums , dp);
                   return  dp[{idx , prev}] = max({pick, notPick, prev});
         }

         int pick =   solve(idx -1 , prev * nums[idx -1 ], nums ,  dp);
         int notPick = solve(idx -1 , nums[idx-1] , nums , dp);

         return  dp[{idx , prev}] = max({pick, notPick, prev});

    }
    int solvingUsingPrefixSuffixApproach(vector<int>&nums , int n){
        int pre = 1 , suff = 1;
        int maxi = -1e9;
        bool isZero = false;
        for(int i = 0; i < n ; i++){
            if(nums[i] == 0 ){
                pre = 1;
                isZero = true;
                continue;
            }
            pre = pre * nums[i];
            maxi = max(pre , maxi);
        }
        for(int i = n-1; i >= 0 ; i--){
            if(nums[i] == 0 ){
                suff = 1;
                isZero = true;
                continue;
            }
            suff = suff * nums[i];
            maxi = max(suff , maxi);
        }

        if(isZero)maxi = max(maxi , 0);
        return maxi;
    }
    int maxProduct(vector<int>& nums) {
        int n  = nums.size();
        // map<pair<int,int>,int>dp;
        // int dpSolutionAns =  solve(n , -1e9 , nums , dp);
        int preSuffAns = solvingUsingPrefixSuffixApproach(nums , n);
        return  preSuffAns;
    }
};

```
</details>

<br> 


<!-- 

# Day 12
## []() 

> Statement

<code >Logic</code>

```quote
Logic
```
[Code Link]()

<details><summary>code</summary>

```cpp
Code
```
</details>

<br> 

 -->
