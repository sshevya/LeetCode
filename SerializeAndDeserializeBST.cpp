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

        stack<TreeNode*> st;
        st.push(root);
        while(root!=NULL || !st.empty()){
            root = st.top();
            st.pop();

            
            if(root!=NULL){
                s+=to_string(root->val);
                s+=",";
            }
            
            if(root!=NULL){
                st.push(root->right);
                st.push(root->left);
            }

        }
        cout<<s<<endl;
        return s;
    }

    TreeNode* insert(TreeNode* root, int val){
        if(root==NULL){
            return new TreeNode(val);
        }


        if(val<=root->val){
            root->left =  insert(root->left, val);
        }
        else{
            root->right = insert(root->right, val);
        }
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        stringstream s(data);
        string str;
        
        if(data==""){
            return NULL;
        }

        getline(s,str,',');
        int val = stoi(str);
        TreeNode* root = new TreeNode(val);
        
        while(str!=""){

            getline(s,str,',');
            cout<<str<<endl;
            if(str==""){
                break;
            }
           insert(root, stoi(str));
        }
      
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
