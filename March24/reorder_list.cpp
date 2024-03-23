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
    void reorderList(ListNode* head) {
        if(head == NULL) return;

        // get the mid 
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        ListNode* middle = slow -> next;
    
        // reverse from next to mid
        ListNode* curr = middle;
        ListNode* prev = NULL;
        ListNode* forward = NULL;

        while(curr) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        slow -> next = NULL;
        
        // reorder the list
        while(head && prev){
            ListNode* temp = head -> next;
            ListNode* prev1 = prev -> next;
            head -> next = prev;
            prev -> next = temp;
            head = temp;
            prev = prev1;
        }        
    }
};
