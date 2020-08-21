/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        unordered_map<Node*,Node*> m;
        Node* temp=head;
        Node* newnode=new Node(head->val);
      //  newnode->next=head->next;
        Node* newHead=newnode;
        m[temp]=newHead;
        
        temp=temp->next;
        while(temp!=NULL){
            
            
            Node* newList=new Node(temp->val);
                    m[temp]=newList;
            newHead->next=newList;

            newHead=newList;
            
            
        /*if(temp->random && m.find(temp->random)==m.end()){
            int v=temp->random->val;
        Node* random=new Node(v);
        random->val=temp->random->val;
        random->next=temp->random->next;
        m[head->random]=random;
        }*/
            
        temp=temp->next;    
            
        }
        
        temp=head;
        newHead=newnode;
        while(temp!=NULL){
            
            if(temp->random){
                newHead->random=m[temp->random];
                
            }else{
                newHead->random=NULL;
            }
            newHead=newHead->next;
            temp=temp->next;
        }
        
        
        return newnode;
    }
};
