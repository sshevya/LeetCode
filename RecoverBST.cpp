
/******* Morris Traversal for O(1) spoace **********/
class Solution {
public:
    void recoverTree(TreeNode* root) {

    
        
        stack<TreeNode*> s;
        TreeNode* curr=root;
        
        long long left_child=-1*LONG_LONG_MAX;
        TreeNode* left_node=root;
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        while(!s.empty() || curr!=NULL){
            while(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            
            
            curr=s.top();
            s.pop();
            
            if(curr->val<left_child){
                if(first==NULL){
                first=left_node;
                   // cout<<first->val<<"F";
                }
                if(first!=NULL){
                second=curr;
              //  cout<<second->val<<"F";
                }
                 
            }
            left_child=curr->val;
            left_node=curr;
            curr=curr->right;
            
        }
        
        if(first!=NULL && second!=NULL){
      int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }
    }
};
