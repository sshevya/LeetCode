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
        
        ListNode* temp=head;
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return false;
        }
        ListNode* hare=head->next->next;
        ListNode* tortoise=head->next;
        
        while(hare!=tortoise && hare!=NULL && hare->next!=NULL && tortoise!=NULL){
            tortoise=tortoise->next;
            hare=hare->next->next;
        }
        
        if(hare==NULL || tortoise==NULL){
            return false;
        }
        hare=head;
        
        while(hare!=tortoise && hare!=NULL && tortoise!=NULL){
        
            hare=hare->next;
            tortoise=tortoise->next;
            }
        if(hare==NULL || tortoise== NULL){
            return false;
        }
        return true;
    }
};
