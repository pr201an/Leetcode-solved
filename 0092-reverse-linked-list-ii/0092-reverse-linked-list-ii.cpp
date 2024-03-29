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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i = 1;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(i<left){
            i++;
            prev = curr;
            curr = curr->next;
        }
        ListNode* con = prev;
        ListNode* tail = curr;
        ListNode* next;
        while(i<=right){
            i++;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(con != NULL)
            con->next = prev;
        else head = prev;
        tail->next = curr;
        return head;
    }
};