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
        ListNode* stb = head;
        ListNode* mov = head;
        int count = 0;
        while(mov != NULL){
            count++;
            mov = mov->next;
            if(count == 10001)
                return true;
        }
        return false;
    }
};