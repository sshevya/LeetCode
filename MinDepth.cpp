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
    void depth(TreeNode* root, int &ans, int level){
        if(root==NULL){
            return;
        }

        if(!root->right && !root->left){
            ans = min(ans, level);
            return;
        }

        depth(root->left, ans, level+1);
        depth(root->right, ans, level+1);
    }

    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int ans = INT_MAX;
        depth(root, ans, 1);
        return ans;
    }
};
