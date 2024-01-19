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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        list<pair<TreeNode*, int>> q;
        int level = 0;
        q.push_back(make_pair(root, level));
        int prev_level = -1;
        vector<int> v;
        TreeNode* curr = root;
        while(!q.empty() && curr!=NULL){

            curr = q.front().first;
            level = q.front().second;
            if(prev_level!=-1 && prev_level<level){
                
                ans.push_back(v);
                v.clear();
            }
            v.push_back(curr->val);
            cout<<curr->val<<" ";
            q.pop_front();

            if(curr->left != NULL){
                q.push_back(make_pair(curr->left, level+1));
            }
            
            if(curr->right!= NULL){
                q.push_back(make_pair(curr->right, level+1));
            }
            prev_level = level;
        }
        
        if(!v.empty()){
            ans.push_back(v);
        }

        return ans;
    }
};
