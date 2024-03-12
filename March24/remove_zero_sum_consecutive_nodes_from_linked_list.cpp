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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* curr = dummy;
        
        while (curr) {
            int sum = 0;
            ListNode* nextNode = curr->next;
            while (nextNode) {
                sum += nextNode->val;
                if (sum == 0) {
                    curr->next = nextNode->next;
                }
                nextNode = nextNode->next;
            }
            curr = curr->next;
        }
        
        return dummy->next;
    }
};
