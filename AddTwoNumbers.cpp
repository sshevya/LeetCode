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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        int carry=0;
        ListNode* head=NULL;
        ListNode* curr=head;
        while(l1 || l2){
            
            
            int val1=(l1==NULL)?0:l1->val;
            int val2=(l2==NULL)?0:l2->val;
            
            int val=val1+val2+carry;
            ListNode* temp=new ListNode(val%10);
            carry=val/10;
            if(!head){
                head=temp;
                curr=temp;
            }else{
            curr->next=temp;
            curr=curr->next;
        }
            if(l1)
            l1=l1->next;
            if(l2)
            l2=l2->next;
        }
        
        
        if(carry!=0){
            ListNode* temp=new ListNode(1);
            curr->next=temp;       
        }
        
        
        
        return head;
        
    }
};
