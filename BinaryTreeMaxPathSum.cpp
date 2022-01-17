class Solution {
public:
    
    int pathSumUtil(TreeNode* root, int& result){
        
        
        if(root==NULL){
            return 0;
        }
        
        int l = pathSumUtil(root->left,result);
        int r = pathSumUtil(root->right, result);
        
        
        int max_single = max(max(l,r)+root->val, root->val);
        
        int max_v = max(max_single, l+r+root->val);
        
        
        result= max(result,max_v);
        
        
        return max_single;
        
        
        
    }
    
    
    
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        
        int v=pathSumUtil(root,result);
        
        return result;
        
    }
};
