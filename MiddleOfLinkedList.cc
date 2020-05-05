/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        int slow_count = 0;
        ListNode* slow_counter = head;
        ListNode* fast_counter = head->next->next;
        while(fast_counter != nullptr && fast_counter->next != nullptr) {
            slow_counter = slow_counter->next;
            slow_count++;
            fast_counter = fast_counter->next->next;
        }
        
        return slow_counter->next;

    }
};