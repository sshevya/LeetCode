/** Sieve of Eratosthenes***/
//Better Solution O(n*log(log(n))
class Solution {
public:
    int countPrimes(int n) {
        
        bool visited[n+1];
        memset(visited,true,sizeof(visited));
        
        for(int i=2;i*i<n;i++){
            if(visited[i]==true){
                for(int j=i*i;j<n;j+=i){
                    visited[j]=false;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
            if(visited[i]==true){
                count++;
            }
        }
        
        return count;
        
    }
};

/**** Second Sol
O(n^3/2)**/
class Solution {
public:
    
    bool isPrime(int n){
        if(n<=1){
            return false;
        }
        if(n<=3){
            return true;
        }
        
        if(n%2==0 || n%3==0){
            return false;
        }
        
        for(int i=5; i*i<=n; i=i+6){
            if(n%i==0 || n%(i+2)==0){
                return false;
            }
        }
        return true;
        
    }
    
    int countPrimes(int n) {
        int count=0;
        
        for(int i=2;i<=n;i++){
            if(isPrime(i)){
                count++;
            }
        }
        if(isPrime(n)){
            count-=1;
        }
        return count;
    }
};
