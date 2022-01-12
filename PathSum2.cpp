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
