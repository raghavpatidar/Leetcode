//--------- Raghav  Patidar---------
// Fuck Ratings,Just Enjoy the Contest/Questions 
// I'm in Love with Experience and Learning.
// Prob : https://leetcode.com/problems/swap-nodes-in-pairs/description/
// Day : 374

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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)return nullptr;
        if(!head->next)return head;
        ListNode* first = head , *second  = head->next;
        while(first and second){
            swap(first->val , second->val);
            first = first->next;
            second = second->next;
            if(first->next and second->next){
                first = first->next;
                second = second->next;
            }else{
                break;
            }
        }
        return head;
    }
};