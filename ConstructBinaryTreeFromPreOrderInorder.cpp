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
    int findIndex(vector<int> &inorder, int root){
        int n = inorder.size();

        for(int i=0;i<n;i++){
            if(root == inorder[i]){
                return i;
            }
        }
        return 0;
    }

    TreeNode* rec(vector<int>& preorder, vector<int> &inorder, int i, int l, int r){
        
        if(l>r || i>=preorder.size()){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[i]);

        int in = findIndex(inorder, root->val);
        cout<<in<<" ";
        root->left = rec( preorder, inorder, i+1, l, in-1);
        root->right = rec(preorder, inorder, i+in-l+1, in+1, r);
        
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        TreeNode* root = rec( preorder, inorder, 0, 0, n-1);
        return root;
    }
};
