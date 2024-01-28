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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;

        stack<TreeNode*> q;
        
        while(!q.empty() || root!=NULL){
            while(root!=NULL){
                v.push_back(root->val);
                if(root->right)
                    q.push(root->right);
                root = root->left;
            }
            
            if(!q.empty()){
                root = q.top();
                q.pop();
            }   

            //root = root->right;
        }

        return v;
    }
};
