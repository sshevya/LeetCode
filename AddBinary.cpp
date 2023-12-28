class Solution {
public:
    string addBinary(string a, string b) {
        int l1 = a.length();
        int l2 = b.length();
        int carry = 0;

        int i = l1 - 1;
        int j = l2 - 1;
        string ans = "";
        while(i>=0 && j>=0){
            if(a[i]=='1'){
                if(b[j]=='1'){
                    if(carry == 1){
                        ans = '1' + ans;
                        carry = 1;    
                    }else{
                        cout<<"k";
                        ans = '0' + ans;
                        carry = 1;
                    }
                    
                }else{
                    if(carry == 1){
                        ans = '0'+ans;
                        carry = 1;
                    }else{
                        ans = '1' + ans;
                        carry = 0;
                    }
                }
            }
            else if (a[i] == '0'){
                if(carry == 0){
                    ans = b[j]+ans;
                    carry = 0;
                }else{
                    if(b[j]=='1'){
                        ans = '0'+ans;
                        carry = 1;
                    }else{
                        ans = '1'+ans;
                        carry = 0;
                    }
                }
            }

            i--;
            j--;
        }

        while(i>=0){
            if(carry == 1){
                if(a[i]=='1'){
                    cout<<"l"<<" ";
                    ans = '0'+ans;
                    carry = 1;
                }else{
                    ans = '1' + ans;
                    carry = 0;
                }
            }else{
                ans = a[i]+ans;
            }
            i--;
        }

        while(j>=0){
            if(carry == 1){
                if(b[j]=='1'){
                    ans = '0'+ans;
                    carry = 1;
                }else{
                    ans = '1' + ans;
                    carry = 0;
                }
            }else{
                ans = b[j]+ans;
            }
            j--;
        }

        if(carry == 1){
            ans = '1'+ans;
        }

        return ans;
    }
};
