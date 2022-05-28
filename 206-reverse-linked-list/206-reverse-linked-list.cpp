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
    ListNode* reverseList(ListNode* head) {
        ListNode * ptr = new ListNode();
        vector<int> v;
        ptr = head;
        while(ptr != NULL){
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        reverse(v.begin(), v.end());
        for(int i=0;i<v.size();i++){
            ptr -> val = v[i];
            ptr = ptr->next;
        }
        return head;
    }
};