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

    bool rec(TreeNode* root, int currSum, int targetSum){

        if(root==NULL){
            return false;
        }      

        bool ans = false;
        currSum = currSum + root->val;

        if(currSum == targetSum){
            if(root->left==NULL && root->right ==NULL){
                return true;
            }
        }
        cout<<currSum<<" ";
        ans = ans | rec(root->left, currSum, targetSum);
        ans = ans | rec(root->right, currSum, targetSum);

        return ans;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        return rec(root, 0, targetSum);
    }
};
