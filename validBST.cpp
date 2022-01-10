class Solution {
public:
    
    bool rec(TreeNode* root, TreeNode* left=NULL, TreeNode* right=NULL ){
        if(root==NULL){
            return true;
        }
        
        if(left!=NULL && root->val<=left->val){
            return false;
        }
        
        
        if(right!=NULL && root->val>=right->val){
            return false;
        }
        
        
        
        return rec(root->left,left, root) and rec(root->right,root,right);
        
        
        
    }
    
    
    bool isValidBST(TreeNode* root) {
        
        return rec(root, NULL,NULL);
    }
};
