class Solution {
public:
    
    Node* getNext(Node* root){
        
        Node* temp= root->next;
        
        
        while(temp!=NULL){
            if(temp->left){
                return temp->left;
            }
            if(temp->right){
                return temp->right;
            }
            temp=temp->next;
        }
        
        return NULL;
        
    }
    
    
    
    Node* connect(Node* head) {
        
        if(!head){
            return NULL;
        }
        
    Node* root=head;
            root->next=NULL;

        while(root!=NULL){
        
        Node* temp = root;

        while(temp!=NULL){
            
            
            if(temp->left){
                if(temp->right){
                    temp->left->next=temp->right;
                    
                }else{
                    temp->left->next = getNext(temp);
                }
            }
            
            
            if(temp->right){
                temp->right->next=getNext(temp);
            }
            
            
            
            
            temp=temp->next;
            
        }
            
            
            
            if(root->left){
                root=root->left;
            }else if(root->right){
                root=root->right;
            }else{
                root=getNext(root);
            }
            
            
        }
        
        
        
        
        
        return head;
        
        
    }
};
