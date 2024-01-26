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
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        if(root==NULL){
            return v;
        }
        list<pair<TreeNode*, int>> q;

        q.push_back(make_pair(root, 0));
        int level = 0;
        int prev_level = 0;
        int largest = INT_MIN;

        while(!q.empty() && root!=NULL){
            root = q.front().first;
            level = q.front().second;
            q.pop_front();

            if(level>prev_level){
                v.push_back(largest);
                largest = root->val;
            }
            else if(level==prev_level){
                largest = max(largest, root->val);
            }

            if(root->left){
                q.push_back(make_pair(root->left, level+1));
            }

            if(root->right){
                q.push_back(make_pair(root->right, level+1));
            }
            prev_level = level;
        }

        v.push_back(largest);
        return v;
    }
};
