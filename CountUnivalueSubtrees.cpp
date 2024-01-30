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
    
    bool countTrees(TreeNode* root, int &count){
       if(root==NULL){
           return true;
       }
    
        if((root->left == NULL && root->right == NULL)){
            count++;
           return true;
        }

        bool left = countTrees(root->left, count);
        bool right = countTrees(root->right, count);

        if(left && right){
           
            if(root->left && root->right){

                if(root->left->val == root->right->val && root->val == root->left->val){
                    count++;
                    return true;
                }
                
                    return false;
            }
            else if(root->left && !root->right){
                if(root->left->val == root->val){
                    count++;
                    return true;
                }
                    return false;
            }
            else if(!root->left && root->right){

                if(root->val == root->right->val){
                    count++;
                    
                    return true;
                }
                    return false;
            }

            return true;
        }
        return false;
    }
        
    int countUnivalSubtrees(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int val = root->val;
        int count =0;
        bool univalue = true;

        countTrees(root,  count);
        return count;
    }
};
