

/******* Optimised sol ****/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int small = min(p->val, q->val);
        int large = max(p->val, q->val);

        while(root!=NULL){
            if(root->val>large){
                root = root->left;
            }
            else if(root->val<small){
                root=root->right;
            }else{
                return root;
            }

           
        }
         return NULL;
    }
};




/****** recursion ****/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    bool findPath(TreeNode* root, vector<TreeNode*> &path, TreeNode* node){
        if(root==NULL){
            return false;
        }
        cout<<root->val<<" ";
        path.push_back(root);

        if(root->val == node->val){
            return true;
        }


        if((root->left && findPath(root->left, path, node)) || (root->right && findPath(root->right, path, node))){
            return true;
        }

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        
        findPath(root, path1, p);
        
        findPath(root, path2, q);
        
        int ind = 0;
        int i = 0;
        cout<<"here "<<path1.size()<<" "<<path2.size();
        for(i=0;i<path1.size() && i<path2.size();i++){
            //cout<<path1[i]->val<<" ";
            if(path1[i]->val!=path2[i]->val){
                return path1[i-1];
            }
        }

        if(i<path1.size()){
            return path1[i-1];
        }

        if(i<path2.size()){
            return path2[i-1];
        }
        return NULL;
    }
};
