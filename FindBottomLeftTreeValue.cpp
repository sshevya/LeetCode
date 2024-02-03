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
    int findBottomLeftValue(TreeNode* root) {
        
        list<pair<TreeNode*, int>> q;
        q.push_back(make_pair(root,0));
        int level = 0;
        int prev_level = -1;
        int bottom = 0;
        int ans = root->val;
        while(!q.empty()){
            root = q.front().first;
            level = q.front().second;
            q.pop_front();

            if(prev_level<level && root->left == NULL && root->right==NULL){
                if(level>bottom){
                    bottom = level;
                    ans = root->val;
                }
                
            }

            if(root->left){
                q.push_back(make_pair(root->left, level+1));
            }

            if(root->right){
                q.push_back(make_pair(root->right, level+1));
            }
            prev_level = level;

        }
        return ans;
    }
};
