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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fass = head;
        ListNode* slow = head;
        while(fass != NULL && fass->next != NULL){
            fass = fass->next->next;
            slow = slow->next;
            if(fass == slow)
                break;
        }
        if(fass == NULL || fass->next == NULL)
            return NULL;
        while(slow != head){
            slow = slow->next;
            head = head->next;
        }
        return head;
    }
};