x/**
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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        list<pair<TreeNode*, int>> q;
        
        q.push_back(make_pair(root,0));
        int level = 0;
        int prev_l = 0;
        TreeNode* prev_node=root;

        while(!q.empty() && root!=NULL){
            root = q.front().first;
            level = q.front().second;
            q.pop_front();
            cout<<root->val<<" "<<q.size()<<endl;

            if(prev_l<level){
                ans.push_back(prev_node->val);
            }

            if(root->left==NULL && root->right==NULL && q.empty()){
                ans.push_back(root->val);
            }

            if(root->left!=NULL){
                q.push_back(make_pair(root->left, level+1));
            }

            if(root->right!=NULL){
                q.push_back(make_pair(root->right, level+1));
            }

            prev_l = level;
            prev_node = root;
        }

        return ans;
    }
};
