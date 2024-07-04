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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head -> next;
        ListNode* h1 = new ListNode(-1);
        ListNode* dummy = h1;
        
        if(head == nullptr) return nullptr;
        while(temp) {
            int sum = 0;

            while(temp -> val != 0){
                sum = sum + temp -> val;
                temp = temp -> next;
            }

            h1 -> next = new ListNode(sum);
            h1 = h1 -> next;
            temp = temp -> next;
        }
        return dummy -> next;
        
    }
};


ListNode* mergeNodes(ListNode* head){
    //BASE CASE -> if we have a single zero, simply return null
    if(!head->next) return nullptr;
    
    //fetch sum from current 0 to next 0
    ListNode* ptr= head->next;
    int sum=0;
    while(ptr->val!=0) sum+= ptr->val, ptr=ptr->next;
    
    //assign sum on the first node between nodes having value 0.
    head->next->val= sum;
    
    //call and get the answer and connect the answer to next of head->next
    head->next->next= mergeNodes(ptr);
    
    //return head->next..=> new head
    return head->next;
}




 ListNode* mergeNodes(ListNode* head) {
     head=head->next;
     ListNode* start=head;
     while(start){
	    ListNode* end= start;   /* Point to first node of current part for getting sum */
        int sum=0;
        while(end->val!=0) sum+= end->val , end=end->next;
        start->val=sum;   /*assign sum to first node between two 0*/
        start->next=end->next;   /*make this connect to first node of next part*/
        start=start->next;    /*go..to..next..part*/
	 }
     return head;
}
