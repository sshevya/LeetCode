
/******* Morris Traversal for O(1) space **********/


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
    void recoverTree(TreeNode* root) {
        TreeNode* val1 = NULL ;
        TreeNode* val2 = NULL;
        TreeNode* prev = NULL;
        TreeNode* predecessor = NULL;

        stack<TreeNode*> s;
       // vector<int> v;
        while(root!=NULL){
            if(root->left == NULL){
                /** compare element **/
                if(val1 == NULL && (prev == NULL || prev->val>=root->val)){
                    val1 = prev;
                }

                if(val1 != NULL && (prev == NULL || prev->val>=root->val)){
                    val2 = root;
                }

                prev = root;
                root = root->right;
            }else{
                predecessor = root->left;

                /* First find inorder predecessor, rightmost child of left subtree*/

                while(predecessor->right!=NULL && predecessor->right!=root){
                    predecessor = predecessor->right;
                }

                /* If not threaded, thread by making right child of this rightmost child as curr 
                *  go to left subtree of current
                *   else revert to original
                **/

                if(predecessor->right==NULL){
                    predecessor->right = root;
                    root = root->left;
                }else{
                    /* restore modified tree to original tree */
                    predecessor->right = NULL;
                    /**compare element */
                    if(val1 == NULL && (prev == NULL || prev->val>=root->val)){
                        val1 = prev;
                    }

                    if(val1 != NULL && (prev == NULL || prev->val >= root->val)){
                        val2 = root;
                    }
                    prev = root;
                    root = root->right;
                }
            }
        }


        cout<<val1->val<<" "<<val2->val<<" ";
        int temp = val1->val;
        val1->val = val2->val;
        val2->val = temp;
        
        
    }
};




/***** Iterative Inorder O(n) space ***********/
class Solution {
public:
    void recoverTree(TreeNode* root) {

    
        
        stack<TreeNode*> s;
        TreeNode* curr=root;
        
        long long left_child=-1*LONG_LONG_MAX;
        TreeNode* left_node=root;
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        while(!s.empty() || curr!=NULL){
            while(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            
            
            curr=s.top();
            s.pop();
            
            if(curr->val<left_child){
                if(first==NULL){
                first=left_node;
                   // cout<<first->val<<"F";
                }
                if(first!=NULL){
                second=curr;
              //  cout<<second->val<<"F";
                }
                 
            }
            left_child=curr->val;
            left_node=curr;
            curr=curr->right;
            
        }
        
        if(first!=NULL && second!=NULL){
      int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }
    }
};
