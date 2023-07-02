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

Problem : https://leetcode.com/problems/design-hashset/submissions/
Day : 388
*/

#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
public:
    vector<bool>m;
    MyHashSet() {
        m.resize(1000005);
    }

    void add(int key) {
        m[key] = 1;
    }

    void remove(int key) {
        m[key] = 0;
    }

    bool contains(int key) {
        return m[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */class MyHashSet {
 public:
     vector<bool>m;
     MyHashSet() {
         m.resize(1000005);
     }

     void add(int key) {
         m[key] = 1;
     }

     void remove(int key) {
         m[key] = 0;
     }

     bool contains(int key) {
         return m[key];
     }
 };

 /**
  * Your MyHashSet object will be instantiated and called as such:
  * MyHashSet* obj = new MyHashSet();
  * obj->add(key);
  * obj->remove(key);
  * bool param_3 = obj->contains(key);
  */