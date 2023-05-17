//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
// Day : 375

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#define Node ListNode
class Solution {
public:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* nextptr = head;
        while (curr) {

            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        return prev;
    }
    int isPalindrome(Node* head)
    {
        if (!head)return 0;
        Node* slow = head;
        Node* fast = head->next;
        while (fast) {
            fast = fast->next;
            if (fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        Node* second = slow->next;
        second = reverse(second);
        int ans = 0;
        while (second) {
            ans = max(ans, head->val + second->val);
            head = head->next;
            second = second->next;
        }
        return ans;
    }
    int pairSum(ListNode* head) {
        return isPalindrome(head);
    }
};