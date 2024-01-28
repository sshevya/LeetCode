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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;

        if(root==NULL){
            return ans;
        }

        list<pair<TreeNode*, int>> q;
        q.push_back(make_pair(root,0));
        
        vector<int> v;
        int level = 0;
        int prev_level = 0;

        while(!q.empty()){
            root = q.front().first;
            level = q.front().second;
            q.pop_front();
            
            if(prev_level<level){
                ans.push_back(v);
                v.clear();
            }

            v.push_back(root->val);

            if(root->left){
                q.push_back(make_pair(root->left, level+1));
            }

            if(root->right){
                q.push_back(make_pair(root->right, level+1));
            }

            prev_level = level;
        }

        if(!v.empty()){
            ans.push_back(v);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
