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
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        int count = 0;
        int max_count = 0;
        int curr_val = root->val;
        while(root!=NULL){
            if(root->left == NULL){
                if(root->val == curr_val){
                    count++;
                }else{
                    count = 1;
                }
                 if(count == max_count){
                    v.push_back(root->val);
                }
                else if(count>max_count){
                    v.clear();
                    v.push_back(root->val);
                    max_count = max(max_count, count);
                }
                curr_val = root->val;

                root = root->right;
            }
            else{
                
                TreeNode* pre = root->left;
                while(pre->right!=NULL && pre->right!=root){
                    pre = pre->right;
                }

                if(pre->right == NULL){
                    pre->right = root;
                    root = root->left;
                }else{
                    pre->right = NULL;
                    if(root->val == curr_val){
                        count++;                                                
                    }else{
                        count = 1;
                    }
                    if(count == max_count){
                        v.push_back(root->val);
                    }
                    else if(count>max_count){
                        v.clear();
                        v.push_back(root->val);
                        max_count = max(max_count, count);
                    }
                    curr_val = root->val;
                    root = root->right;

                }

            }
        
        }
        return v;
    }
};
