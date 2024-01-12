class Solution {
public:
    
    class Trie{
    public:
        class Node{
        public:
            Node* left;
            Node* right;
            Node() : left(nullptr), right(nullptr) {};
        };
        
        Node* root;
        
        Trie(){
            root = new Node();
        }

        void insert(int val){
            int bitIndex = 30;
            Node* curr = root;

            while(bitIndex>=0){
                int mask = 1<<bitIndex;
                int bit = (mask&val) >0? 1:0;

                if(bit == 0){
                    if(curr->left == nullptr){
                        curr->left = new Node();
                    }
                    curr = curr->left;
                }
                else{
                    if(curr->right == nullptr){
                        curr->right = new Node();
                    }
                    curr = curr->right;
                }
                bitIndex--;
            }
        }

        int query(int find){
            int bitIndex = 30;
            Node* curr = root;
            int ans = 0;

            while(bitIndex>=0){
                int mask = 1<<bitIndex;
                int bit = (find&mask) >0? 1:0;

                if(bit==0){
                    if(curr->left!=nullptr){
                        curr=curr->left;
                    }else{
                        curr = curr->right;
                        ans |= mask;
                    }
                }else{
                    if(curr->right!=nullptr){
                        curr=curr->right;
                        ans |= mask;
                    }else{
                        curr = curr->left;
                    }
                }
                bitIndex--;
            }
            return ans;
        }

    };
    
    
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;//= new Trie();

        for(int val: nums){
            trie.insert(val);
        }

        int max = 0;

        for(int a: nums){
            int find = INT_MAX^a;
            int b = trie.query(find);
            max = std::max(max, a^b);
        }
        return max;
    }
};
