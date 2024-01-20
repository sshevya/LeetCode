/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    TreeNode* rec(vector<int> &v, int l, int r){
        if(l>r){
            return NULL;
        }

        int mid = l+(r-l)/2;

        TreeNode* root = new TreeNode(v[mid]);

        root->left = rec(v, l, mid-1);
        root->right = rec(v, mid+1, r);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // vector<int> v;

        // while(head!=NULL){
        //     v.push_back(head->val);
        //     head = head->next;
        // }

        // return rec(v, 0, v.size()-1);

        if(head==NULL){
            return NULL;
        }

        if(head->next == NULL){
            TreeNode* node = new TreeNode(head->val);
            return node;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->next->val);
        ListNode* right = slow->next->next;
        slow->next = NULL;
        
        root->left = sortedListToBST(head);
        
        root->right = sortedListToBST(right);


        return root;
    }
};
