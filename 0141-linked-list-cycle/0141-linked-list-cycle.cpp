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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fass = head;
        while(fass != NULL && fass->next != NULL){
            slow = slow->next;
            fass = fass->next->next;
            if(slow == fass)
                return true;
        }
        return false;
    }
};