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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL){
            return head;
        }
        
        if(head->next==NULL){
            return head;
        }
        
        ListNode* temp=head;
        
        ListNode* temp_head=temp->next;
        temp->next=temp_head->next;
        temp_head->next=temp;
        
        ListNode* prev=temp;
        ListNode* curr=temp->next;
        ListNode* Next;
           
        
        while(curr!=NULL && curr->next!=NULL){
            
            Next=curr->next;
            prev->next=Next;
            curr->next=Next->next;
            Next->next=curr;

            prev=curr;
            curr=curr->next;
            
            
        }
        
        
        return temp_head;
    }
};
