class Solution {
public:
    
    void rec(TreeNode* root){
        if(root==NULL || (root->right==NULL && root->left==NULL)){
            return ;
        }
        
        
        if(root->left!=NULL){
            rec(root->left);
            
            
            TreeNode* temp = root->right;
            
            root->right=root->left;
            
            root->left = NULL;
            
            TreeNode* temp2=root->right;
            
            while(temp2->right!=NULL){
                temp2=temp2->right;
                
            }
            
            temp2->right=temp;
            
            
            
        }
        
        
        rec(root->right);
        
    }
    
    
    void flatten(TreeNode* root) {
        
        
        
        rec(root);
        
        
        
    }
};
