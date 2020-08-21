class Solution {
public:
    /*void swap(char* a, char* b){
        char* temp=a;
        a=b;
        b=temp;
    }*/
    void reverseString(vector<char>& s) {
       
        int l=0;
        int r=s.size()-1;
        
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
        
        return;
        
        
    }
};
