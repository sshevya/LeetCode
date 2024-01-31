class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;

        int lower_bound = INT_MIN;

        for(int i=0;i<preorder.size();i++){
            if(s.empty() || preorder[i]<preorder[i-1]){
                if(preorder[i]<lower_bound){
                    return false;
                }
                s.push(preorder[i]);
            }
            else{
                while(!s.empty() && s.top()<preorder[i]){
                    lower_bound = s.top();
                    s.pop();
                }

                s.push(preorder[i]);
            }
        }
        return true;
    }
};
