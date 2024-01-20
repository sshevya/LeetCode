/*** Solution 1 ***/

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

    void backtrack(TreeNode* root, vector<vector<int>> &ans, vector<int> curr, int currSum, int targetSum){
        if(root==NULL){
            return;
        }

        int val = root->val;
        currSum += val;
        curr.push_back(val);
        cout<<currSum<<" "<<curr.back()<<endl;
        if(currSum == targetSum){
            if(root->left == NULL && root->right==NULL){
                ans.push_back(curr);
                return;
            }
        }

        backtrack(root->left, ans, curr, currSum, targetSum);       
        backtrack(root->right, ans, curr, currSum, targetSum);
        currSum -= val;
        curr.pop_back();
        return;
    }
    

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;

        vector<int> curr;

        backtrack(root, ans, curr, 0, targetSum);
        return ans;
    }
};


/*** Solution 2 *****/

class Solution {
public:
    
    void backtrack(TreeNode* root, int val, vector<vector<int>> &ans, vector<int>& v){
        
        
        if(root==NULL){
            return;
        }
        
        if(val==0 && root->left==NULL && root->right==NULL){
            //v.push_back(root->val);
            ans.push_back(v);
        }
        
        if(root->left){
            v.push_back(root->left->val);
            
            backtrack(root->left,val-root->left->val,ans,v);
            v.pop_back();
            
            
        }
        
        
        if(root->right){
            
            v.push_back(root->right->val);
            
            backtrack(root->right,val-root->right->val,ans,v);
            v.pop_back();
            
            
        }
        
        return;
        
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans;
        vector<int> v;
        if(root==NULL){
            return ans;
        }
        
        v.push_back(root->val);
        
        backtrack(root,targetSum-root->val,ans,v);
        return ans;
        
    }
};
