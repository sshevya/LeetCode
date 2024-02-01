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




/****** O(n) sol **********/

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans(k,0) ;
        int closest = INT_MAX;
        list<TreeNode*> q;
        set<pair<double,int>> diff_set;
        double diff = 0;
        q.push_back(root);

        while(!q.empty() && root!=NULL){
            root = q.front();
            q.pop_front();

            diff = abs(root->val-target);
            diff_set.insert(make_pair(diff, root->val));

            if(root->left){
                q.push_back(root->left);
            }

            if(root->right){
                q.push_back(root->right);
            }
        }

        
        int count=0;
        for(auto i=diff_set.begin();i!=diff_set.end();i++){
            ans[count++] = i->second;
            if(count==k){
                break;
            }
        }

        return ans;
    }
};
