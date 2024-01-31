/************* Recursive Sol ************/

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

    void rec(TreeNode* root, double target, double &ans){
        if(root==NULL){
            return;
        }

        if(abs(root->val-target) < abs(ans - target)){
            ans = root->val;
        }
        
        if(abs(root->val-target) == abs(ans - target)){
            if(root->val<ans){
                ans = root->val;
            }
        }

        rec(root->left, target, ans);
        rec(root->right, target, ans);

        return;
    }


    int closestValue(TreeNode* root, double target) {
        double ans = root->val;
        rec(root, target, ans);

        return ans;
    }
};







/*********** Morris Traversal Constant Space Iterative ******/

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


    int closestValue(TreeNode* root, double target) {
        double ans = root->val;

        while(root!=NULL){
            if(root->left==NULL){
                cout<<ans<<" "<<root->val<<endl;
                if(abs(root->val-target) < abs(ans - target)){
                    ans = root->val;
                }
                
                if(abs(root->val-target) == abs(ans - target)){
                    if(root->val<ans){
                        ans = root->val;
                    }
                }

                root = root->right;
            }else{
                TreeNode* curr = root->left;
                while(curr->right!=NULL && curr->right !=root){
                    curr = curr->right;
                }

                if(curr->right==NULL){
                    curr->right = root;
                    root = root->left;
                }
                else{
                    curr->right = NULL;
                    if(abs(root->val-target) < abs(ans - target)){
                        ans = root->val;
                    }
                    
                    if(abs(curr->val-target) == abs(ans - target)){
                        if(root->val<ans){
                            ans = root->val;
                        }
                    }
                    root = root->right;
                }
            }
        }


        return ans;
    }
};
