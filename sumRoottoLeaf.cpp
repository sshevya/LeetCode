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
    
    void sum(TreeNode* root,int val, int& result){
        
        if(root==NULL){
            return;
        }
        
        if(root->left ==NULL && root->right==NULL){

            val+=root->val;
            result+=val;
            return;
        }
        
        
        val+=root->val;
        val*=10;
        sum(root->left,val,result);
        sum(root->right,val,result);
        return;
        
    }
    
    
    
    
    
    int sumNumbers(TreeNode* root) {
        int val=0;
        int result=0;
        sum(root,val,result);
        return result;
    }
};
