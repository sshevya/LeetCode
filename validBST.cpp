//Iterative inorder based solution

class Solution {
public:
    
    
    bool isValidBST(TreeNode* root) {
        
        stack<TreeNode*> s;
        TreeNode* curr=root;
        
        long long left_child=-1*LONG_LONG_MAX;
        while(!s.empty() || curr!=NULL){
            while(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            
            
            curr=s.top();
            s.pop();
            
            if(curr->val<=left_child){
                return false;
            }
            left_child=curr->val;
            curr=curr->right;
            
        }
        
        return true;
        
    }
};


//Recursive

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
