

/******* Questions expects another implementation try that*******/

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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans(k,0) ;
        
        if(root == NULL){
            return ans;
        }
        int closest = INT_MAX;
        stack<TreeNode*> s;
        deque<int> q;
        double diff = 0;
        //s.push(root);
        while(!s.empty() || root!=NULL){
            
            while(root!=NULL){
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();
            cout<<root->val<<" ";
            q.push_back(root->val);
            if(q.size()>k){
                if(abs(target - q.front()) < abs(target - q.back())){
                    cout<<"here"<<q.front();
                    break;
                }else{

                    q.pop_front();
                    cout<<"here"<<q.front();
                }
            }
            root = root->right;
        }

        
        int i=0;
        while(!q.empty() && i!=k){
            ans[i]=q.front();
            i++;
            q.pop_front();
        }

        return ans;
    }
};
