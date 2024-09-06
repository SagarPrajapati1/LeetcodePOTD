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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        if(!head) return NULL;
        unordered_set<int> st;

        // insert all element in the set
        for(auto it: nums){
            st.insert(it);
        }
        ListNode* temp = new ListNode(-1);
        temp -> next = head;
        ListNode* prev = temp;
        ListNode* curr = head;

        while(curr) {
            // if current element in the set
            if(st.find(curr -> val) != st.end()) {
                // store the current ka next element
                prev -> next = curr -> next;
                // delete the curre node
                delete curr;
                // update the current node to next one
                curr = prev -> next;
            }
            // if not in the set
            else {
                // update the prev to current
                prev = curr;
                // move forward curr to next one
                curr = curr -> next;
            }
        }

        // return the next of dummy node
        return temp -> next;
        
    }
};
