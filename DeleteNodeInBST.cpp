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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL){
            return root;
        }
        
        TreeNode* curr = root;
        TreeNode* parent = NULL;
        
        while(curr!=NULL && curr->val!=key){
            parent = curr;

            if(curr->val > key){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }

        //if curr is NULL that means node to be deleted is not present in tree
        if(curr == NULL){
            return root;
        }
        
        if(!curr->left || !curr->right){
            TreeNode* child = curr->left? curr->left : curr->right;
            if(!parent){
                //only one child and parent is null, that means the child wil be returned
                root = child;
            }
            else if(parent->left == curr){
                parent->left = child;
            }else{
                parent->right = child;
            }
        }else{
            TreeNode* temp = curr;

            parent = curr;
            curr = curr->right;

            while(curr->left){
                parent = curr;
                curr = curr->left;
            }
            temp->val = curr->val;

            if(parent ->left == curr){
                parent ->left = curr->right;
            }else{
                parent->right = curr->right;
            }
        }

        delete(curr);
        return root;
    }
};
