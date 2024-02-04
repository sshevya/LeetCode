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
    

    string serialize(TreeNode* root, unordered_map<string, int>& m, vector<TreeNode*> &v){
        if(root==NULL){
            return "#";
        }

        string s = serialize(root->left, m, v) +','+ serialize(root->right, m, v)+','+ to_string(root->val);
        m[s]++;
        cout<<root->val<<" "<<m[s]<<endl;
        if(m[s]==2){
            
            v.push_back(root);
        }

        return s;

    }



    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        unordered_map<string, int> m;
        vector<TreeNode*> v;

        serialize(root, m, v);

        return v;
    }
};
