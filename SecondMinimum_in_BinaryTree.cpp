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
   /* int findminimum(TreeNode* root){
        TreeNode* temp=root;
        while(temp->left){
            temp=temp->left;
        }
        
        return temp->val;
        
        
        
    }*/
    
    //can be optimized for BST see commented code or InterviewCake
    void inorder(TreeNode* root, set<int> &v){
        if(!root){
            return;
        }
        inorder(root->left,v);
        if(v.find(root->val)==v.end())
        v.insert(root->val);
    
        inorder(root->right,v);
    }
    int findSecondMinimumValue(TreeNode* root) {
        
        
     /*   if(!root ||( !root->left && !root->right)){
            return 0;
        }
        
        
    
        TreeNode* temp=root;
        
        while(true){
            
            if(temp->right && !temp->left){
                return findminimum(temp->right);
            }
            
            
            if(temp->left && !temp->left->left && !temp->left->right){
                break;
            }
            temp=temp->left;
            
        }        
        
        
        
        
        return temp->val;
    }*/
        
        set<int> v;
        inorder(root,v);
        if(v.size()<=1){
            return -1;  
        }
        set<int>::iterator i=v.begin();
        i++;
        int a=*i;
        return a;
    }
};
