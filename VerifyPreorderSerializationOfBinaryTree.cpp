class Solution {
public:
    bool isValidSerialization(string preorder) {
        
      
        stringstream s(preorder);

        string str;

        
        
        int nodes = 1;
        while(getline(s,str,',')){
            nodes--;
            if(nodes<0){
                return false;
            }
            if(str!="#"){
                nodes+=2;
            }
        }

        return nodes==0;

    }
};
