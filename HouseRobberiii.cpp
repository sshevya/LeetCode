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

    int rec(TreeNode* root, unordered_map<TreeNode*, int> &m){
        if(root==NULL){
            return 0;
        }

        if(m.find(root)!=m.end()){
            return m[root];
        }

        int val = 0;
        if(root->left){
            val+=rec(root->left->left, m)+rec(root->left->right, m);
        }
        
        if(root->right){
            val+=rec(root->right->left,m)+rec(root->right->right, m);
        }
        
        int ans = max(val+root->val, rec(root->left, m)+rec(root->right, m));

        m[root] = ans;
        return ans;
    }

    int rob(TreeNode* root) {
        
        
        if(root == NULL){
            return 0;
        }

        if(root->left==NULL && root->right==NULL){
            return root->val;
        }


        int maxSum = 0;
        unordered_map<TreeNode*, int>  m;
        maxSum=rec(root, m);
        return maxSum;
    }
};
