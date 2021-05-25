class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        
        
        string news = "";
        string a = "";
        int n = s.length();
        int group = 0;
        
        /*int j =0;
        while(s[j]=='-'){
            j++;
        }  
        for(int i=n-1;i>=j;i--){
            
                if(s[i]=='-'){
                    continue;
                }else{
                    if(s[i]>='a' && s[i]<='z'){
                        news=(char)(s[i]-32)+news;
                        group++;
                        
                    }else{
                        news=s[i]+news;
                        group++;
                    }
                    
                    
                }
            
            if(group==k && i!=j){
                news='-'+news;
                group=0;
            }  
            
        }*/
        
        
        
        for(int i=0;i<n;i++){
            if(s[i]!='-'){
                if(s[i]>='a'&& s[i]<='z'){
                    a+=s[i]-32;
                }else{
                    a+=s[i];
                }
            }
        }
        
        n = a.length();
        
        int l = n%k;
        int i ;
        for(i=0;i<l;i++){
            news+=a[i];
        }
      
        if(l!=0 && l!=n){
            news+='-';
        }
        
        for(;i<n;i++){
            news+=a[i];
            group++;
            if(group==k && i!=n-1){
                news+='-';
                group=0;
            }
        }
        
        
        
       return news;
    }
};
