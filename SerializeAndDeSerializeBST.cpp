/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root==NULL){
            return "null";
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            root = q.front();
            q.pop();

            if(root==NULL){
                s+="null,";
            }else{
                s+=to_string(root->val);
                s+=",";
            }

            if(root!=NULL){
                q.push(root->left);
                q.push(root->right);
            }
            
            
        }
        return s;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       cout<<data<<" ";
        if(data.size() == 0){
            return NULL;
        }

        stringstream s(data);

        string str;

        getline(s, str, ',');

        if(str == "null"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            getline(s, str, ',');
            if(str=="null"){
                curr->left = NULL;
            }else{
                TreeNode* left = new TreeNode(stoi(str));
                curr->left = left;
                q.push(left);
            }

            getline(s, str, ',');
            if(str=="null"){
                curr->right = NULL;
            }else{
                TreeNode* right = new TreeNode(stoi(str));
                curr->right = right;
                q.push(right);
            }
        }

        return root;    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
