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
    
    
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head && head -> val == val) {
            ListNode* temp = head;
            head = head -> next;
            delete temp;
        }
        
        if(head == NULL) return NULL;
        
        ListNode* pre = head;
        ListNode* cur = head -> next;
        while(cur) {
            if(cur -> val == val) {
                ListNode* temp = cur;
                pre -> next = cur -> next;
                cur = cur -> next;
                delete temp;
            } else {
                pre = pre -> next;
                cur = cur -> next;
            }
        }
        return head;
    }
    
};
