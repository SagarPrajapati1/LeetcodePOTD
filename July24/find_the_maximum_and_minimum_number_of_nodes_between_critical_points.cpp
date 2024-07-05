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
    int getLength (ListNode* head) {
        int len = 0;
        while(head){
            len++;
            head = head -> next;
        }
        return len;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pos;
        ListNode* temp = head;

        if(head == nullptr) return {};

        ListNode* prev = head;
        ListNode* curr = head -> next;
        ListNode* forward = curr -> next;
        int cnt = 1;

        int len = getLength(head);
        if(len < 3) return {-1, -1};
        while(forward) {

            // local maxima
            if (prev -> val < curr -> val && curr -> val > forward -> val) {
                pos.push_back(cnt);
            }

            // local minim
            if (prev -> val > curr -> val && curr -> val < forward -> val) {
                pos.push_back(cnt);
            }

            cnt++;
            curr = curr -> next;
            forward = forward -> next;
            prev = prev -> next;
        }
        int sz=pos.size();
        if (sz<=1) return {-1, -1};
        else{
            int maxD=pos.back()-pos[0];
            int minD=INT_MAX;
            for(int i=0; i<sz-1; i++)
                minD=min(minD, pos[i+1]-pos[i]);
            return {minD, maxD};
        }
    }
};
