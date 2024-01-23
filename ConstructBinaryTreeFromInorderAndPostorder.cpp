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
    int findIndex(vector<int> inorder, int target){
        int i = 0;
        for(i=0;i<inorder.size();i++){
            if(inorder[i]==target){
                return i;
            }
        }
        return i;
    }

    TreeNode* buildUtil(int l, int r, int ind, vector<int> &inorder, vector<int> &postorder){

       if( l>r || ind>=inorder.size() || ind<0){
           return NULL;
       }     

        int i = findIndex(inorder, postorder[ind]);

        TreeNode* node = new TreeNode(postorder[ind]);

        if(l==r){
            return node;
        }

        cout<<l<<" "<<r<<" "<<ind<<" "<<i<<endl;
        node->left = buildUtil(l, i-1, ind - (r-i)-1 ,inorder, postorder);
        node->right = buildUtil(i+1, r, ind-1 , inorder, postorder);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildUtil(0, inorder.size()-1, postorder.size()-1, inorder, postorder);
    }
};
