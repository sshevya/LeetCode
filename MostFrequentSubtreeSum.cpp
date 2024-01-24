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

    int rec(TreeNode* root, unordered_map<int, int> &m, int &max_freq){

        if(root==NULL){
            return 0;
        }

        int sum = root->val;

        sum += rec(root->left, m, max_freq);
        sum += rec(root->right, m, max_freq);

        m[sum]++;
        max_freq = max(max_freq, m[sum]);
        return sum;
    }


    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        unordered_map<int, int> m;
        vector<int> ans;
        int max_freq = 0;
        int sum = rec(root, m, max_freq);

       for(auto &i: m){
           if(i.second == max_freq){
               ans.push_back(i.first);
           }
       }


        return ans;
    }
};
