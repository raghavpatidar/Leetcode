//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/kth-largest-element-in-a-stream/submissions/955839157/
// Day : 380

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > p;
    int K = 0;
    KthLargest(int k, vector<int>& nums) {
        // p.clear();
        K = k;
        for (auto i : nums) {
            p.push(i);
            if (p.size() > k)p.pop();
        }
    }

    int add(int val) {
        p.push(val);
        if (p.size() > K)p.pop();
        return p.top();

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */