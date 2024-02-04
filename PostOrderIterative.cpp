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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> v;

        stack<TreeNode*> q;
        if(root==NULL){
            return v;
        }
        //q.push(root);
        TreeNode* prev = NULL;
        while(!q.empty() || root!=NULL){
            
            while(root!=NULL){
                
                if(root->right){
                    //cout<<root->right->val<<" ";

                    q.push(root->right);
                }
               // cout<<root->val<<" ";
                q.push(root);
                root = root->left;
            }
            
            root = q.top();
            q.pop();

            if(root!=NULL && root->right!=NULL && ( !q.empty() && root->right == q.top())){
                
                TreeNode *right = q.top();
                q.pop();
                
                q.push(root);
                root = root->right;
            }else{
                v.push_back(root->val);
                root = NULL;
            }
        }

        return v;
    }
};
