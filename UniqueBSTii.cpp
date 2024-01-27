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

    string getStringMapping(TreeNode* root){

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            s += to_string(it->val);
            if(it->left!=NULL){
                q.push(it->left);
            }else{
                s+="null";
            }

            if(it->right!=NULL){
                q.push(it->right);
            }else{
                s+="null";
            }
        }

        return s;
    }

    TreeNode* constructBST(vector<int> &v, unordered_map<string,int> &s){
        int n = v.size();

        TreeNode* root = new TreeNode(v[0]);

        for(int i=1;i<n;i++){
            TreeNode* curr = root;
            while(curr){
                if(v[i]<curr->val){
                    if(!curr->left && v[i]!=curr->val){
                        curr->left = new TreeNode(v[i]);
                    }
                    curr = curr->left;
                }else{
                    if(!curr->right && v[i]!=curr->val){
                        curr->right = new TreeNode(v[i]);
                    }
                    curr = curr->right;
                }  
            }                  
        }

        string temp = getStringMapping(root);
            if(s.find(temp)!=s.end()){
                return NULL;
            }else{
                s[temp] = 1;
            }
        return root;
    }


    vector<TreeNode*> generateTrees(int n) {
        unordered_map<string, int> m;
        vector<int> v;
        vector<TreeNode*> ans;


        for(int i=1;i<=n;i++){
            v.push_back(i);
        }

        do{
            TreeNode* root = constructBST(v, m);
            if(root){
                ans.push_back(root);
            }
        }while(next_permutation(v.begin(),v.end()));

       return ans;
    }
};
