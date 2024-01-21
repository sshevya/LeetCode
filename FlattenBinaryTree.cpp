/**** less complicated ******/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* rec(TreeNode* root){
        
        TreeNode* curr = root;
        
        if(root==NULL){
            return NULL;
        }

        TreeNode* right = rec(root->right);

        TreeNode* left = rec(root->left);

        root->right = left;
        root->left = NULL;
        
        while(root->right!=NULL){
            root=root->right;
        }
        
        root->right = right;



        return curr;
    }


    void flatten(TreeNode* root) {

        root = rec(root);
        
    }
};










/********* old sol ******/
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
