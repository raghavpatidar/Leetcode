

/*
Hi ,
I Am Raghav Patidar
question : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
day : 373


--------- Raghav  Patidar---------
 Fuck Ratings,Just Enjoy the Contest
I'm in Love with Experience.
Day : 373
Prob : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

*/


class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        k--;
        ListNode* second = head;
        for (int i = 0; i < k; i++)
        {
            if (!first) {
                break;
            }
            first = first->next;
        }
        ListNode* firstref = first;
        while (first->next != nullptr) {
            second = second->next, first = first->next;
        }
        swap(firstref->val, second->val);
        return head;
    }
};