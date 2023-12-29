class Solution {
public:

    long long encode(char c, long long i){
        long long base = 0;

        if(c== 'C'){
            base = 10;
        }else if(c == 'G'){
            base = 20;
        }else if(c == 'T'){
            base = 30;
        }
        
        bitset<sizeof(long long)*8> binary_c(1ll<<(base+i)); 
        cout<<c<<" "<<base<<" "<<i<<" "<<(base+i)<<" ";
        return 1LL<<(base + i);
    }

    char decode(long int i){
        char res = 'A';
        int base = i/10;
        if(base == 1){
            res = 'C';
        }else if(base ==2){
            res='G';
        }else if(base ==3){
            res= 'T';
        }
        return res;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ans;

        if(n<10){
            return ans;
        }
        long long current = 0;
        for(int i=0;i<10;i++){
            current |= encode(s[i], i);
            bitset<sizeof(long long)*8> binary_c(current); 
           cout<<current<<" "<<binary_c<<endl;
        }

        unordered_map<long long, int> seen;
        set<long long> res;
        seen[current]=1;
        bitset<sizeof(long long)*8> binary_c(current); 
        cout<<binary_c<<endl;
        for(int i=1;i<n-9;i++){
            current ^= encode(s[i-1], 0);
            current>>=1;
            current |= encode(s[i+9], 9);
            
            if(seen.find(current)!=seen.end()){
                bitset<sizeof(long long)*8> binary_c(current); 
                cout<<binary_c<<endl;
                res.insert(current);
            }else{
                seen[current] = 1;
            }
        }


        for(auto encoded: res){
           
            string decoded(10, ' ');
            int count = 0;
            for(long long i=0;i<40;i++){
                if((1LL<<i) & encoded){                  
                    decoded[i%10] = decode(i);
                    count++;
                }
                if(count == 10){                    
                    break;
                }

            }
            ans.push_back(decoded);
        }

        return ans;
    }
};
