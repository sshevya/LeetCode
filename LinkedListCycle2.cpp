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
    ListNode *detectCycle(ListNode *head) {
        ListNode* NoNode=NULL;
        ListNode* temp=head;
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return NoNode;
        }
        ListNode* hare=head->next->next;
        ListNode* tortoise=head->next;
        
        while(hare!=tortoise && hare!=NULL && hare->next!=NULL && tortoise!=NULL){
            tortoise=tortoise->next;
            hare=hare->next->next;
        }
        
        if(hare==NULL || tortoise==NULL){
            return NoNode;
        }
        hare=head;
        
        while(hare!=tortoise && hare!=NULL && tortoise!=NULL){
        
            hare=hare->next;
            tortoise=tortoise->next;
            }
        if(hare==NULL || tortoise== NULL){
            return NoNode;
        }
        return hare;
    
    }
};
