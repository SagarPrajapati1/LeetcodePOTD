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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;

        // find the length
        ListNode* temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp -> next;
        }

        // check if len is >= n or not
        if(len < n) return nullptr;

        if(len == n){
            ListNode* head1 = head -> next;
            delete head;
            return head1;
        }
        

        temp = head;
        for(int i = 1; i < len - n; i ++){
            temp = temp -> next;
        }

        ListNode* nextNode = temp -> next;
        temp -> next = nextNode -> next;
        delete nextNode;
        return head;
    }
};
