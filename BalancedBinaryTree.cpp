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

    int rec(TreeNode* root, bool &ans){
        if(root==NULL){
            return 0;
        }

        int left = rec(root->left, ans);
        int right = rec(root->right, ans);
        //cout<<root->val<<" "<<left<<" "<<right<<" "<<(left-right)<<endl;
        if(abs(left-right)>=2){
            //cout<<ans<<" ";
            ans = ans & false;
        }else{
            ans = ans & true;
        }

        

        return 1+max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        bool ans = true;
        rec(root, ans);

        return ans;
    }
};
