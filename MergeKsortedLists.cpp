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
    
    ListNode* merge(ListNode* a, ListNode* b){
        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
            
        }
        
        
        ListNode* res=NULL;
        if(a->val<=b->val){
            res=a;
            res->next=merge(a->next,b);
        }else{
            res=b;
            res->next=merge(a,b->next);
        }
        
        return res;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
        ListNode* a;
        int n=lists.size();
        if(n==0){
            return a;
        }
        int i=0;
        int j=n-1;
        int k=n-1;
        
        while(k!=0){
            i=0;
            j=k;
            while(i<j){
            lists[i]=merge(lists[i],lists[j]);
            i++;
            j--;
            if(i>=j){
                k=j;
            }
            }
            
        }
     return lists[0];   
    }
};
